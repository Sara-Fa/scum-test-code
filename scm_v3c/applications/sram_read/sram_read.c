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

//=========================== prototypes ======================================

//=========================== main ============================================


int main(void) {
    uint32_t i;
		uint32_t j=0;
		uint64_t *adr;
	
    memset(&app_vars,0,sizeof(app_vars_t));
    
    printf("Initializing...");
        
    initialize_mote();
    crc_check();
    perform_calibration();
  	
		adr=(uint64_t*)0x20005000;
		for(j=0;j<8;j++)
		{
			printf("address %p \t", adr);
			printf("value %"PRIu64"\r \n", *adr);
			adr++;
		}
		
		app_vars.count += 1;
		//changed
		for (i = 0; i < 1000000; i++);

}

//=========================== public ==========================================

//=========================== private =========================================
