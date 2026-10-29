// Pins from hardware/wearable-node-boost-ldo-v2 schematic (Processor.kicad_sch, U1)

// GREEN_LED (D5, via R32 330R). D4 is a fixed power LED on +3V3.
#define LED_PIN 4
#define LED_STATE_ON 1 // State when LED is lit

// SW2 (BOOT).
#define BUTTON_PIN 0
#define BUTTON_NEED_PULLUP

// PANIC_BTN read by the Detection Sensor module when its monitor pin is left at 0 in the node config.
#define DETECTION_SENSOR_PIN 1

// BUZZER_EN: gate of low-side MOSFET Q2; LS1 is self-driven, so plain on/off.
#define EXT_NOTIFY_OUT 2

// VBAT_SENSE: 100k/100k divider (R16/R17) from VBAT_SW
#define BATTERY_PIN 8
#define ADC_CHANNEL ADC1_GPIO8_CHANNEL
#define ADC_MULTIPLIER 2.0
#define BATTERY_SENSE_RESOLUTION_BITS 12

// 1-cell LiFePO4: typical OCV in mV, 100% to 0%. Tune against the real cell.
#define OCV_ARRAY 3400, 3350, 3320, 3290, 3270, 3260, 3250, 3230, 3200, 3120, 3000

// CHG_STAT: BQ25171 STAT2 via R2 (1k), pulled low while charging.
// CHG_FAULT (BQ25171 STAT1) is on IO17, unused by the firmware.
#define EXT_CHRG_DETECT 9
#define EXT_CHRG_DETECT_VALUE LOW

// MAX-M10S via the JP4 shunts. GPS_INT (IO6, EXTINT) is unused.
#define HAS_GPS 1
#define GPS_RX_PIN 16 // GPS_TXO
#define GPS_TX_PIN 15 // GPS_RXI
#define PIN_GPS_PPS 7
#define PIN_GPS_RESET 5
#define GPS_RESET_MODE LOW
#define GPS_THREAD_INTERVAL 50

// J6 sensor header
#define I2C_SDA 42
#define I2C_SCL 41

// UART0 goes to the J8 debug header (IO38-40 are there too, unused).
#define UART_TX 43
#define UART_RX 44

// Wio-SX1262 (U7)
#define USE_SX1262

#define LORA_MISO 13
#define LORA_SCK 12
#define LORA_MOSI 11
#define LORA_CS 10
#define LORA_RESET 14
#define LORA_DIO1 21

#ifdef USE_SX1262
#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY 48
#define SX126X_RESET LORA_RESET

// DIO2 drives the antenna switch, DIO3 the TCXO. RF_SW1 (IO47) is RX enable.
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_RXEN 47
#define SX126X_TXEN RADIOLIB_NC
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif
