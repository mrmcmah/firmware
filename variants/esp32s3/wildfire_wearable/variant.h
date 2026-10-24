// Pins from hardware/wearable-node-boost-ldo schematic

// GREEN_LED (D4). D3 is a fixed power LED on +3V3.
#define LED_PIN 15
#define LED_STATE_ON 1 // State when LED is lit

// SW2 (BOOT). The panic button (SW4, IO21) is read by the Detection Sensor module.
#define BUTTON_PIN 0
#define BUTTON_NEED_PULLUP

// BUZZER_EN: gate of low-side MOSFET Q2; LS1 is self-driven, so plain on/off.
#define EXT_NOTIFY_OUT 2

// VBAT_SENSE: 100k/100k divider (R12/R13)
#define BATTERY_PIN 1
#define ADC_CHANNEL ADC1_GPIO1_CHANNEL
#define ADC_MULTIPLIER 2.0
#define BATTERY_SENSE_RESOLUTION_BITS 12

// 1-cell LiFePO4: typical OCV in mV, 100% to 0%. Tune against the real cell.
#define OCV_ARRAY 3400, 3350, 3320, 3290, 3270, 3260, 3250, 3230, 3200, 3120, 3000

// CHG_STAT: BQ25171 STAT2, pulled low while charging
#define EXT_CHRG_DETECT 3
#define EXT_CHRG_DETECT_VALUE LOW

// MAX-M10S via the JP4 shunts. GPS_INT (IO17, EXTINT) is unused.
#define HAS_GPS 1
#define GPS_RX_PIN 7 // GPS_TXO
#define GPS_TX_PIN 8 // GPS_RXI
#define PIN_GPS_PPS 16
#define PIN_GPS_RESET 18
#define GPS_RESET_MODE LOW
#define GPS_THREAD_INTERVAL 50

// J6 sensor header
#define I2C_SDA 5
#define I2C_SCL 6

// UART0's pins carry LoRa SPI on this board, so UART0 must stay unused.
#define UART_TX 43
#define UART_RX 44

// Wio-SX1262 (U6)
#define USE_SX1262

#define LORA_MISO 43
#define LORA_SCK 44
#define LORA_MOSI 9
#define LORA_CS 41

#define LORA_RESET 42
#define LORA_DIO1 39

#ifdef USE_SX1262
#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY 40
#define SX126X_RESET LORA_RESET

// DIO2 drives the antenna switch, DIO3 the TCXO. RF_SW1 (IO38) is RX enable.
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_RXEN 38
#define SX126X_TXEN RADIOLIB_NC
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
#endif
