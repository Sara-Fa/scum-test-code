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

//uint64_t altstack[10] __attribute__ ((section ("STACK")));


//void foo(void) {
//		int cnt=0;
//    uint64_t bcd1[8];    // automatic storage - contain junk
//		for(cnt=0;cnt<8;cnt++)
//	{
//		printf("address %p \n", &bcd1[cnt]);
//    printf("value %"PRIu64"\n", bcd1[cnt]);
//	}
//}

//int bcd2;
//const int bcd3=0;

int main(void) {
    uint32_t i;
		uint32_t j=0;
		uint64_t *adr;
//		int bcd4;
//		int bcd5=0;
    //uint64_t b[3];  
		
		//uint64_t j;
		//uint64_t *p=(uint64_t*)malloc(5*sizeof(uint64_t));
		
//		uint64_t k[20];
//		p=&k[0];
		//uint64_t *p;
		//p=&j;
	
    memset(&app_vars,0,sizeof(app_vars_t));
    
    printf("Initializing...");
        
    initialize_mote();
    crc_check();
    perform_calibration();
    
    //while(1){
	
//		printf("size of altstack %d \n", sizeof(altstack));
//		printf("element 0 of altstack %"PRIu64"\n", altstack[0]);
		//foo();
				//printf("address of pointer %p \n", &p);
//				printf("address %p \n", &k[0]);
//				printf("value %"PRIu64"\n", k[0]);
//				//p=p-1;
//				printf("address %p \n", &k[1]);
//				printf("value %"PRIu64"\n", k[1]);
						
					
//				printf("#############");
//				printf("address %p \n", &j);
//				printf("value %"PRIu64"\n", j);
//				printf("address %p \n", &k);
//				printf("value %"PRIu64"\n", k);
//				printf("address %p \n", &l);
//				printf("value %"PRIu64"\n", l);
//				printf("address %p \n", &m);
//				printf("value %"PRIu64"\n", m);
		
				
				adr=(uint64_t*)0x20005000;
				for(j=0;j<8;j++)
				{
					printf("address %p \t", adr);
					printf("value %"PRIu64"\r \n", *adr);
//					if((*adr)==0)
//					{j++;
//						printf("address %p \n", adr);}
				
					adr++;
				}
//				printf("there is %d zero values \n",j);
//				if(j==0)
//					printf("all the values are =0");
//				else
//					printf("not all the values are =0");
//				
        app_vars.count += 1;
        
				//changed
        for (i = 0; i < 1000000; i++);
    //}
}

//=========================== public ==========================================

//=========================== private =========================================
