//PMW33XX_CS_PIN	(Required) Sets the Chip Select pin connected to the sensor.	POINTING_DEVICE_CS_PIN
#define PMW33XX_CS_PIN F7

//PMW33XX_CS_PINS	(Alternative) Sets the Chip Select pins connected to multiple sensors.	{PMW33XX_CS_PIN}
//PMW33XX_CS_PIN_RIGHT	(Optional) Sets the Chip Select pin connected to the sensor on the right half.	PMW33XX_CS_PIN
//PMW33XX_CS_PINS_RIGHT	(Optional) Sets the Chip Select pins connected to multiple sensors on the right half.	{PMW33XX_CS_PIN_RIGHT}
//PMW33XX_CPI	(Optional) Sets counts per inch sensitivity of the sensor.	varies
//PMW33XX_CLOCK_SPEED	(Optional) Sets the clock speed that the sensor runs at.	2000000
//PMW33XX_SPI_DIVISOR	(Optional) Sets the SPI Divisor used for SPI communication.	varies
//PMW33XX_LIFTOFF_DISTANCE	(Optional) Sets the lift off distance at run time	0x02
//ROTATIONAL_TRANSFORM_ANGLE	(Optional) Allows for the sensor data to be rotated +/- 127 degrees directly in the sensor.	0