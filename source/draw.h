#ifndef _DRAW_H
#define _DRAW_H

void reset0ref(void);

void moveto(
	signed int y,
	signed int x
	);

void draw_vlist_c(
	const signed char *vList
	);

void draw_vlist_c_pattern(
	const signed char *vList, const signed char pattern
	);

void draw_synced_list_c_nm(
	const signed char *u,
	unsigned int scaleList
	);

void draw_synced_list_c_nm1(
	const signed char *u,
	unsigned int scaleMove,
	unsigned int scaleList
	);


#define ZERO_DELAY 5

__NO_INLINE void draw_vlp_1(const signed char *x);

__NO_INLINE void draw_vlp_2(const signed char *x);


__INLINE void draw_synced_list_c(
    const signed char *u,
    signed int y,
    signed int x,
    unsigned int scaleMove,
    unsigned int scaleList
    )
{
    
    do
    {
        // resnyc / startsync
        dp_VIA_shift_reg = 0;        // all output is BLANK
        
        // move to zero
        dp_VIA_cntl = (unsigned int)0xcc;    // zero the integrators
        dp_VIA_port_a = 0;            // reset integrator offset
        dp_VIA_port_b = (int)0b10000010;
        
        dp_VIA_t1_cnt_lo = scaleMove;
        // delay, till beam is at zero
        // volatile - otherwise delay loop does not work with -O
        for (volatile signed int b=ZERO_DELAY; b>0; b--);
        dp_VIA_port_b= (int)0b10000011;
        
        // move to "location"
        dp_VIA_port_a = y;            // y pos to dac
        dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
        dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
        dp_VIA_port_b = 1;            // mux disable, dac only to x
        dp_VIA_port_a = x;            // dac -> x
        dp_VIA_t1_cnt_hi=0;        // start timer
        
        // this can be done before the wait loop
        // since it only fills the latch, not the actual timer!
        dp_VIA_t1_cnt_lo = scaleList;
        u+=3;
        
        // moveing test for yx== 0 into the move delay
        if ((*(u-2)!=0) || (*(u-1)!=0))
        {
            while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
            
            // internal moveTo
            dp_VIA_port_a = *(u-2);    // y pos to dac
            dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
            dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
            dp_VIA_port_b = 1;            // mux disable, dac only to x
            dp_VIA_port_a = *(u-1);    // dac -> x
            dp_VIA_t1_cnt_hi=0;        // start timer
            while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
        }
        else
        {
            while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
        }
        
        while (1)
        {
            if (*u<0) // draw line
            {
                // draw a vector
                dp_VIA_port_a = *(1+u);        // y pos to dac
                dp_VIA_port_b = 0;                // mux enable, dac to -> integrator y (and x)
 asm ("nop");
                dp_VIA_port_b=1;                // mux disable, dac only to x
                dp_VIA_port_a = *(2+u);        // dac -> x
                if (scaleList>0)
                {
                    dp_VIA_shift_reg = (unsigned int)0x1f;//%00011111;// 0xff;    // draw complete line
                		dp_VIA_t1_cnt_hi=0;            // start timer
                    while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
//					asm("nop");
//					asm("nop");
                    dp_VIA_shift_reg = 0;            // all output is BLANK
                }
                else
				{
                    dp_VIA_shift_reg = (unsigned int)0x1f;//%00011111;// 0xff;    // draw complete line
                 	dp_VIA_t1_cnt_hi=0;            // start timer
                    dp_VIA_shift_reg = (unsigned int)0xF0;//%11110000;// 0xff;    // draw complete line
					}
            }
            else if (*u == 0) // moveTo
            {
                if ((*(u+1)!=0) || (*(u+2)!=0))
                {
                    // internal moveTo
                    dp_VIA_port_a = *(1+u);    // y pos to dac
                    dp_VIA_cntl = (unsigned int)0xce;    // disable zero, disable all blank
                    dp_VIA_port_b = 0;            // mux enable, dac to -> integrator y (and x)
                    dp_VIA_port_b =1;            // mux disable, dac only to x
                    dp_VIA_port_a = *(2+u);    // dac -> x
                    dp_VIA_t1_cnt_hi=0;        // start timer
                    while ((dp_VIA_int_flags & 0x40) == 0); // wait till timer finishes
                }
            }
            else
            {
                break;
            }
            u+=3;
        }
    } while (*u != 2);
}


#endif

