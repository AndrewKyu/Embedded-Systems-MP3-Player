/*
 * VS1053.h
 *
 *  Created on: Nov 21, 2018
 *      Author: John (Offline)
 */

#ifndef VS1053_H_
#define VS1053_H_

#include "vs10xx_uc.h"
#include "LabSPI0.h"
#include "gpio.hpp"
#include <FreeRTOS.h>
#include "task.h"
//#include "ssp0.h"
#include "storage.hpp"
#include <stdio.h>
#include <string.h>


class VS1053 {
public:
    void init(LPC1758_GPIO_Type DREQ, LPC1758_GPIO_Type _CS, LPC1758_GPIO_Type _DCS);
    void spiwrite(uint8_t c);
    void spiwrite(uint8_t *c, uint16_t num);
    uint8_t spiread(void);
    void sciWrite(uint8_t addr, uint16_t data);
    uint16_t sciRead(uint8_t addr);
    void sineTest(uint8_t n, uint16_t ms);
    void soft_reset(void);
    void sendVolume(uint8_t left, uint8_t right);
    void setVolume(uint8_t vol);
    void setBalance(uint8_t bal);
    virtual ~VS1053();
    VS1053();
    GPIO* DREQ;
    GPIO* _CS;
    GPIO* _DCS;
    LabSpi0 SPI0;
    uint8_t volume;
};

#endif /* VS1053_H_ */
