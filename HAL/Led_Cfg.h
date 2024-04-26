/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for Led 
 *
 * Author: Mohamed Hassan
 ******************************************************************************/
#ifndef LED_CFG_H
#define LED_CFG_H


/* Set the LED Port */
#define LED_PORT DioConf_LED1_PORT_NUM

/* Set the LED Pin Number */
#define LED_PIN_NUM DioConf_LED1_CHANNEL_NUM 
#define LED_PIN_NUM_INDEX DioConf_LED1_CHANNEL_ID_INDEX  

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON  STD_HIGH
#define LED_OFF STD_LOW

#endif /* LED_CFG_H*/
