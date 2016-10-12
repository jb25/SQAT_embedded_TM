/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

#include "swm.h"
#include "delay.h"
#include "i2c.h"
#include "display.h"
//
#include "tm.h"

int main(void)
{
#if defined (__USE_LPCOPEN)
    SystemCoreClockUpdate();
#endif
    swm_config_i2c();
    i2c_reset();
	disp_on( DISP_SHOW_NONE );
	disp_reset( DISP_SHOW_NONE );

	tm_reset_data();
	/**
	 * TODO: Oscar to remove this
	 */

	int i;
	for( i=0; i<9; i++){
		tm_handle_sensor();
	}
	display_message_t trend = tm_get_trend();
	disp_show_message( trend );
	/**
	 * TODO: Oscar to remove until here
	 */


	while( 1 ){
		/**
		 * TODO: Oscar to remove this
		 */






		tm_handle_sensor();
		trend = tm_get_trend();
		disp_show_message( trend );
		/**
		 * TODO: Oscar to remove until here
		 */
	}
    return 0 ;
}
