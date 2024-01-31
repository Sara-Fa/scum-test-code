#include <string.h>

//added by Sara (to print uint64 correctly)
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#include "scm3c_hw_interface.h"
#include "memory_map.h"
#include "optical.h"

//=========================== defines =========================================

#define CRC_VALUE         (*((unsigned int *) 0x0000FFFC))
#define CODE_LENGTH       (*((unsigned int *) 0x0000FFF8))

//=========================== variables =======================================

typedef struct {
    uint8_t count;
} app_vars_t;

app_vars_t app_vars;

//global variables allocated in the non-initialized section defined inside the scatter file
//uint64_t Unique_ID1 __attribute__( ( section( "NoInit"),zero_init) ) ;
//uint64_t Unique_ID2 __attribute__( ( section( "NoInit"),zero_init) ) ;


//=========================== prototypes ======================================

//=========================== main ============================================


int main(void) {
    uint32_t i;
		uint32_t j=0;
		uint64_t *adr;
		uint64_t *max_adr;
	
    memset(&app_vars,0,sizeof(app_vars_t));
    
    printf("Initializing...");
        
    initialize_mote();
    crc_check();
    perform_calibration();
	
	
		// print the global values allocated in the non-initialized section
//		printf("Inside noInit section: Unique_ID1: 0x%"PRIx64"\r \n",Unique_ID1);
//		printf("Inside noInit section: Unique_ID2: 0x%"PRIx64"\r \n",Unique_ID2);
//	


//////////////////////////////////////////////

		// read full program SRAM memory
//	  adr = (uint64_t*)0x00000000;
//		max_adr = (uint64_t*)0x00010000;
//		i = 1;
//		while( adr < max_adr )
//		{
//			printf("Program SRAM, kB number %d \n",i);
//			for(j=0; j<128; j++)
//			{
//				printf("0x%"PRIx64" ", *adr); //print in hexadecimal
//				adr++;
//			}
//			i++;
//			printf("\r\n\n");
//		 }

//////////////////////////////////////////////
	
		// read full data SRAM memory
//		adr = (uint64_t*)0x20000000;
//		max_adr = (uint64_t*)0x20010000;
//		i = 1;
//		while( adr < max_adr )
//		{
//			printf("Data SRAM, kB number %d \n",i);
//			for(j=0; j<128; j++)
//			{
//				printf("0x%"PRIx64" ", *adr); //print in hexadecimal
//				adr++;
//			}
//			i++;
//			printf("\r\n\n");
//		}
		
//////////////////////////////////////////////
		
		// read 55kB non-initialized part of the data memory, in a continuous way
		adr = (uint64_t*)0x20002400;
		max_adr = (uint64_t*)0x20010000;
		while( adr < max_adr )
		{
			printf("%"PRIx64"", *adr); //print in hexadecimal
			adr++;
		}
		
	
		app_vars.count += 1;
		//changed
		for (i = 0; i < 1000000; i++);

}

//=========================== public ==========================================

//=========================== private =========================================
