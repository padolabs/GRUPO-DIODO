/*
 * app.c
 *
 *  Created on: Mar 24, 2022
 *      Author: gabrielly
 */

 #include "app.h"

 extern SPI_HandleTypeDef hspi1;
 extern uint8_t data_array[2];
 uint8_t transmit_array[2];
 uint8_t tx_address[5] = {0xE7,0xE7,0xE7,0xE7,0xE7};
 uint8_t rx_address[5] = {0xD7,0xD7,0xD7,0xD7,0xD7};

 void app_init(){

 }

 void app_run(){
	 nrf24_init();

	 nrf24_config(2, sizeof(data_array));

	 nrf24_tx_address(rx_address);
	 nrf24_rx_address(tx_address);

	 while (1){

		if(nrf24_dataReady()) {
			nrf24_getData(data_array);
			HAL_GPIO_WritePin(led_GPIO_Port, led_Pin, 1);
			HAL_Delay(50);
			HAL_GPIO_WritePin(led_GPIO_Port, led_Pin, 0);
			transmit_array[0] = corrente;
			nrf24_send(transmit_array);
		}
	 }
 }

