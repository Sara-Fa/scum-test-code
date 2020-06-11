#ifndef __FREQ_SETTING_SELECTION_H
#define __FREQ_SETTING_SELECTION_H

#include <stdint.h>

//=========================== define ==========================================

//=========================== typedef =========================================

//=========================== variables =======================================

//=========================== prototypes ======================================

//==== admin
uint16_t freq_setting_selection_reference(
    uint16_t* setting_list, 
    int8_t* freq_offset_list
);

uint16_t freq_setting_selection_median(
    uint16_t* setting_list
);

#endif