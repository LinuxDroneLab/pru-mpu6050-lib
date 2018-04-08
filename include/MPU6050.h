#ifndef _MPU6050_H_
#define _MPU6050_H_

#include <pru_i2c_driver.h>

#define pgm_read_byte(p) (*(uint8_t *)(p))

#define MPU6050_ADDRESS_AD0_LOW     0x68 // address pin low (GND), default for InvenSense evaluation board
#define MPU6050_ADDRESS_AD0_HIGH    0x69 // address pin high (VCC)
#define MPU6050_DEFAULT_ADDRESS     MPU6050_ADDRESS_AD0_LOW

#define MPU6050_RA_XG_OFFS_TC       0x00 //[7] PWR_MODE, [6:1] XG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_YG_OFFS_TC       0x01 //[7] PWR_MODE, [6:1] YG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_ZG_OFFS_TC       0x02 //[7] PWR_MODE, [6:1] ZG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6050_RA_X_FINE_GAIN      0x03 //[7:0] X_FINE_GAIN
#define MPU6050_RA_Y_FINE_GAIN      0x04 //[7:0] Y_FINE_GAIN
#define MPU6050_RA_Z_FINE_GAIN      0x05 //[7:0] Z_FINE_GAIN
#define MPU6050_RA_XA_OFFS_H        0x06 //[15:0] XA_OFFS
#define MPU6050_RA_XA_OFFS_L_TC     0x07
#define MPU6050_RA_YA_OFFS_H        0x08 //[15:0] YA_OFFS
#define MPU6050_RA_YA_OFFS_L_TC     0x09
#define MPU6050_RA_ZA_OFFS_H        0x0A //[15:0] ZA_OFFS
#define MPU6050_RA_ZA_OFFS_L_TC     0x0B
#define MPU6050_RA_XG_OFFS_USRH     0x13 //[15:0] XG_OFFS_USR
#define MPU6050_RA_XG_OFFS_USRL     0x14
#define MPU6050_RA_YG_OFFS_USRH     0x15 //[15:0] YG_OFFS_USR
#define MPU6050_RA_YG_OFFS_USRL     0x16
#define MPU6050_RA_ZG_OFFS_USRH     0x17 //[15:0] ZG_OFFS_USR
#define MPU6050_RA_ZG_OFFS_USRL     0x18
#define MPU6050_RA_SMPLRT_DIV       0x19
#define MPU6050_RA_CONFIG           0x1A
#define MPU6050_RA_GYRO_CONFIG      0x1B
#define MPU6050_RA_ACCEL_CONFIG     0x1C
#define MPU6050_RA_FF_THR           0x1D
#define MPU6050_RA_FF_DUR           0x1E
#define MPU6050_RA_MOT_THR          0x1F
#define MPU6050_RA_MOT_DUR          0x20
#define MPU6050_RA_ZRMOT_THR        0x21
#define MPU6050_RA_ZRMOT_DUR        0x22
#define MPU6050_RA_FIFO_EN          0x23
#define MPU6050_RA_I2C_MST_CTRL     0x24
#define MPU6050_RA_I2C_SLV0_ADDR    0x25
#define MPU6050_RA_I2C_SLV0_REG     0x26
#define MPU6050_RA_I2C_SLV0_CTRL    0x27
#define MPU6050_RA_I2C_SLV1_ADDR    0x28
#define MPU6050_RA_I2C_SLV1_REG     0x29
#define MPU6050_RA_I2C_SLV1_CTRL    0x2A
#define MPU6050_RA_I2C_SLV2_ADDR    0x2B
#define MPU6050_RA_I2C_SLV2_REG     0x2C
#define MPU6050_RA_I2C_SLV2_CTRL    0x2D
#define MPU6050_RA_I2C_SLV3_ADDR    0x2E
#define MPU6050_RA_I2C_SLV3_REG     0x2F
#define MPU6050_RA_I2C_SLV3_CTRL    0x30
#define MPU6050_RA_I2C_SLV4_ADDR    0x31
#define MPU6050_RA_I2C_SLV4_REG     0x32
#define MPU6050_RA_I2C_SLV4_DO      0x33
#define MPU6050_RA_I2C_SLV4_CTRL    0x34
#define MPU6050_RA_I2C_SLV4_DI      0x35
#define MPU6050_RA_I2C_MST_STATUS   0x36
#define MPU6050_RA_INT_PIN_CFG      0x37
#define MPU6050_RA_INT_ENABLE       0x38
#define MPU6050_RA_DMP_INT_STATUS   0x39
#define MPU6050_RA_INT_STATUS       0x3A
#define MPU6050_RA_ACCEL_XOUT_H     0x3B
#define MPU6050_RA_ACCEL_XOUT_L     0x3C
#define MPU6050_RA_ACCEL_YOUT_H     0x3D
#define MPU6050_RA_ACCEL_YOUT_L     0x3E
#define MPU6050_RA_ACCEL_ZOUT_H     0x3F
#define MPU6050_RA_ACCEL_ZOUT_L     0x40
#define MPU6050_RA_TEMP_OUT_H       0x41
#define MPU6050_RA_TEMP_OUT_L       0x42
#define MPU6050_RA_GYRO_XOUT_H      0x43
#define MPU6050_RA_GYRO_XOUT_L      0x44
#define MPU6050_RA_GYRO_YOUT_H      0x45
#define MPU6050_RA_GYRO_YOUT_L      0x46
#define MPU6050_RA_GYRO_ZOUT_H      0x47
#define MPU6050_RA_GYRO_ZOUT_L      0x48
#define MPU6050_RA_EXT_SENS_DATA_00 0x49
#define MPU6050_RA_EXT_SENS_DATA_01 0x4A
#define MPU6050_RA_EXT_SENS_DATA_02 0x4B
#define MPU6050_RA_EXT_SENS_DATA_03 0x4C
#define MPU6050_RA_EXT_SENS_DATA_04 0x4D
#define MPU6050_RA_EXT_SENS_DATA_05 0x4E
#define MPU6050_RA_EXT_SENS_DATA_06 0x4F
#define MPU6050_RA_EXT_SENS_DATA_07 0x50
#define MPU6050_RA_EXT_SENS_DATA_08 0x51
#define MPU6050_RA_EXT_SENS_DATA_09 0x52
#define MPU6050_RA_EXT_SENS_DATA_10 0x53
#define MPU6050_RA_EXT_SENS_DATA_11 0x54
#define MPU6050_RA_EXT_SENS_DATA_12 0x55
#define MPU6050_RA_EXT_SENS_DATA_13 0x56
#define MPU6050_RA_EXT_SENS_DATA_14 0x57
#define MPU6050_RA_EXT_SENS_DATA_15 0x58
#define MPU6050_RA_EXT_SENS_DATA_16 0x59
#define MPU6050_RA_EXT_SENS_DATA_17 0x5A
#define MPU6050_RA_EXT_SENS_DATA_18 0x5B
#define MPU6050_RA_EXT_SENS_DATA_19 0x5C
#define MPU6050_RA_EXT_SENS_DATA_20 0x5D
#define MPU6050_RA_EXT_SENS_DATA_21 0x5E
#define MPU6050_RA_EXT_SENS_DATA_22 0x5F
#define MPU6050_RA_EXT_SENS_DATA_23 0x60
#define MPU6050_RA_MOT_DETECT_STATUS    0x61
#define MPU6050_RA_I2C_SLV0_DO      0x63
#define MPU6050_RA_I2C_SLV1_DO      0x64
#define MPU6050_RA_I2C_SLV2_DO      0x65
#define MPU6050_RA_I2C_SLV3_DO      0x66
#define MPU6050_RA_I2C_MST_DELAY_CTRL   0x67
#define MPU6050_RA_SIGNAL_PATH_RESET    0x68
#define MPU6050_RA_MOT_DETECT_CTRL      0x69
#define MPU6050_RA_USER_CTRL        0x6A
#define MPU6050_RA_PWR_MGMT_1       0x6B
#define MPU6050_RA_PWR_MGMT_2       0x6C
#define MPU6050_RA_BANK_SEL         0x6D
#define MPU6050_RA_MEM_START_ADDR   0x6E
#define MPU6050_RA_MEM_R_W          0x6F
#define MPU6050_RA_DMP_CFG_1        0x70
#define MPU6050_RA_DMP_CFG_2        0x71
#define MPU6050_RA_FIFO_COUNTH      0x72
#define MPU6050_RA_FIFO_COUNTL      0x73
#define MPU6050_RA_FIFO_R_W         0x74
#define MPU6050_RA_WHO_AM_I         0x75

#define MPU6050_TC_PWR_MODE_BIT     7
#define MPU6050_TC_OFFSET_BIT       6
#define MPU6050_TC_OFFSET_LENGTH    6
#define MPU6050_TC_OTP_BNK_VLD_BIT  0

#define MPU6050_VDDIO_LEVEL_VLOGIC  0
#define MPU6050_VDDIO_LEVEL_VDD     1

#define MPU6050_CFG_EXT_SYNC_SET_BIT    5
#define MPU6050_CFG_EXT_SYNC_SET_LENGTH 3
#define MPU6050_CFG_DLPF_CFG_BIT    2
#define MPU6050_CFG_DLPF_CFG_LENGTH 3

#define MPU6050_EXT_SYNC_DISABLED       0x0
#define MPU6050_EXT_SYNC_TEMP_OUT_L     0x1
#define MPU6050_EXT_SYNC_GYRO_XOUT_L    0x2
#define MPU6050_EXT_SYNC_GYRO_YOUT_L    0x3
#define MPU6050_EXT_SYNC_GYRO_ZOUT_L    0x4
#define MPU6050_EXT_SYNC_ACCEL_XOUT_L   0x5
#define MPU6050_EXT_SYNC_ACCEL_YOUT_L   0x6
#define MPU6050_EXT_SYNC_ACCEL_ZOUT_L   0x7

#define MPU6050_DLPF_BW_256         0x00
#define MPU6050_DLPF_BW_188         0x01
#define MPU6050_DLPF_BW_98          0x02
#define MPU6050_DLPF_BW_42          0x03
#define MPU6050_DLPF_BW_20          0x04
#define MPU6050_DLPF_BW_10          0x05
#define MPU6050_DLPF_BW_5           0x06

#define MPU6050_GCONFIG_FS_SEL_BIT      4
#define MPU6050_GCONFIG_FS_SEL_LENGTH   2

#define MPU6050_GYRO_FS_250         0x00
#define MPU6050_GYRO_FS_500         0x01
#define MPU6050_GYRO_FS_1000        0x02
#define MPU6050_GYRO_FS_2000        0x03

#define MPU6050_ACONFIG_XA_ST_BIT           7
#define MPU6050_ACONFIG_YA_ST_BIT           6
#define MPU6050_ACONFIG_ZA_ST_BIT           5
#define MPU6050_ACONFIG_AFS_SEL_BIT         4
#define MPU6050_ACONFIG_AFS_SEL_LENGTH      2
#define MPU6050_ACONFIG_ACCEL_HPF_BIT       2
#define MPU6050_ACONFIG_ACCEL_HPF_LENGTH    3

#define MPU6050_ACCEL_FS_2          0x00
#define MPU6050_ACCEL_FS_4          0x01
#define MPU6050_ACCEL_FS_8          0x02
#define MPU6050_ACCEL_FS_16         0x03

#define MPU6050_DHPF_RESET          0x00
#define MPU6050_DHPF_5              0x01
#define MPU6050_DHPF_2P5            0x02
#define MPU6050_DHPF_1P25           0x03
#define MPU6050_DHPF_0P63           0x04
#define MPU6050_DHPF_HOLD           0x07

#define MPU6050_TEMP_FIFO_EN_BIT    7
#define MPU6050_XG_FIFO_EN_BIT      6
#define MPU6050_YG_FIFO_EN_BIT      5
#define MPU6050_ZG_FIFO_EN_BIT      4
#define MPU6050_ACCEL_FIFO_EN_BIT   3
#define MPU6050_SLV2_FIFO_EN_BIT    2
#define MPU6050_SLV1_FIFO_EN_BIT    1
#define MPU6050_SLV0_FIFO_EN_BIT    0

#define MPU6050_MULT_MST_EN_BIT     7
#define MPU6050_WAIT_FOR_ES_BIT     6
#define MPU6050_SLV_3_FIFO_EN_BIT   5
#define MPU6050_I2C_MST_P_NSR_BIT   4
#define MPU6050_I2C_MST_CLK_BIT     3
#define MPU6050_I2C_MST_CLK_LENGTH  4

#define MPU6050_CLOCK_DIV_348       0x0
#define MPU6050_CLOCK_DIV_333       0x1
#define MPU6050_CLOCK_DIV_320       0x2
#define MPU6050_CLOCK_DIV_308       0x3
#define MPU6050_CLOCK_DIV_296       0x4
#define MPU6050_CLOCK_DIV_286       0x5
#define MPU6050_CLOCK_DIV_276       0x6
#define MPU6050_CLOCK_DIV_267       0x7
#define MPU6050_CLOCK_DIV_258       0x8
#define MPU6050_CLOCK_DIV_500       0x9
#define MPU6050_CLOCK_DIV_471       0xA
#define MPU6050_CLOCK_DIV_444       0xB
#define MPU6050_CLOCK_DIV_421       0xC
#define MPU6050_CLOCK_DIV_400       0xD
#define MPU6050_CLOCK_DIV_381       0xE
#define MPU6050_CLOCK_DIV_364       0xF

#define MPU6050_I2C_SLV_RW_BIT      7
#define MPU6050_I2C_SLV_ADDR_BIT    6
#define MPU6050_I2C_SLV_ADDR_LENGTH 7
#define MPU6050_I2C_SLV_EN_BIT      7
#define MPU6050_I2C_SLV_BYTE_SW_BIT 6
#define MPU6050_I2C_SLV_REG_DIS_BIT 5
#define MPU6050_I2C_SLV_GRP_BIT     4
#define MPU6050_I2C_SLV_LEN_BIT     3
#define MPU6050_I2C_SLV_LEN_LENGTH  4

#define MPU6050_I2C_SLV4_RW_BIT         7
#define MPU6050_I2C_SLV4_ADDR_BIT       6
#define MPU6050_I2C_SLV4_ADDR_LENGTH    7
#define MPU6050_I2C_SLV4_EN_BIT         7
#define MPU6050_I2C_SLV4_INT_EN_BIT     6
#define MPU6050_I2C_SLV4_REG_DIS_BIT    5
#define MPU6050_I2C_SLV4_MST_DLY_BIT    4
#define MPU6050_I2C_SLV4_MST_DLY_LENGTH 5

#define MPU6050_MST_PASS_THROUGH_BIT    7
#define MPU6050_MST_I2C_SLV4_DONE_BIT   6
#define MPU6050_MST_I2C_LOST_ARB_BIT    5
#define MPU6050_MST_I2C_SLV4_NACK_BIT   4
#define MPU6050_MST_I2C_SLV3_NACK_BIT   3
#define MPU6050_MST_I2C_SLV2_NACK_BIT   2
#define MPU6050_MST_I2C_SLV1_NACK_BIT   1
#define MPU6050_MST_I2C_SLV0_NACK_BIT   0

#define MPU6050_INTCFG_INT_LEVEL_BIT        7
#define MPU6050_INTCFG_INT_OPEN_BIT         6
#define MPU6050_INTCFG_LATCH_INT_EN_BIT     5
#define MPU6050_INTCFG_INT_RD_CLEAR_BIT     4
#define MPU6050_INTCFG_FSYNC_INT_LEVEL_BIT  3
#define MPU6050_INTCFG_FSYNC_INT_EN_BIT     2
#define MPU6050_INTCFG_I2C_BYPASS_EN_BIT    1
#define MPU6050_INTCFG_CLKOUT_EN_BIT        0

#define MPU6050_INTMODE_ACTIVEHIGH  0x00
#define MPU6050_INTMODE_ACTIVELOW   0x01

#define MPU6050_INTDRV_PUSHPULL     0x00
#define MPU6050_INTDRV_OPENDRAIN    0x01

#define MPU6050_INTLATCH_50USPULSE  0x00
#define MPU6050_INTLATCH_WAITCLEAR  0x01

#define MPU6050_INTCLEAR_STATUSREAD 0x00
#define MPU6050_INTCLEAR_ANYREAD    0x01

#define MPU6050_INTERRUPT_FF_BIT            7
#define MPU6050_INTERRUPT_MOT_BIT           6
#define MPU6050_INTERRUPT_ZMOT_BIT          5
#define MPU6050_INTERRUPT_FIFO_OFLOW_BIT    4
#define MPU6050_INTERRUPT_I2C_MST_INT_BIT   3
#define MPU6050_INTERRUPT_PLL_RDY_INT_BIT   2
#define MPU6050_INTERRUPT_DMP_INT_BIT       1
#define MPU6050_INTERRUPT_DATA_RDY_BIT      0

// TODO: figure out what these actually do
// UMPL source code is not very obivous
#define MPU6050_DMPINT_5_BIT            5
#define MPU6050_DMPINT_4_BIT            4
#define MPU6050_DMPINT_3_BIT            3
#define MPU6050_DMPINT_2_BIT            2
#define MPU6050_DMPINT_1_BIT            1
#define MPU6050_DMPINT_0_BIT            0

#define MPU6050_MOTION_MOT_XNEG_BIT     7
#define MPU6050_MOTION_MOT_XPOS_BIT     6
#define MPU6050_MOTION_MOT_YNEG_BIT     5
#define MPU6050_MOTION_MOT_YPOS_BIT     4
#define MPU6050_MOTION_MOT_ZNEG_BIT     3
#define MPU6050_MOTION_MOT_ZPOS_BIT     2
#define MPU6050_MOTION_MOT_ZRMOT_BIT    0

#define MPU6050_DELAYCTRL_DELAY_ES_SHADOW_BIT   7
#define MPU6050_DELAYCTRL_I2C_SLV4_DLY_EN_BIT   4
#define MPU6050_DELAYCTRL_I2C_SLV3_DLY_EN_BIT   3
#define MPU6050_DELAYCTRL_I2C_SLV2_DLY_EN_BIT   2
#define MPU6050_DELAYCTRL_I2C_SLV1_DLY_EN_BIT   1
#define MPU6050_DELAYCTRL_I2C_SLV0_DLY_EN_BIT   0

#define MPU6050_PATHRESET_GYRO_RESET_BIT    2
#define MPU6050_PATHRESET_ACCEL_RESET_BIT   1
#define MPU6050_PATHRESET_TEMP_RESET_BIT    0

#define MPU6050_DETECT_ACCEL_ON_DELAY_BIT       5
#define MPU6050_DETECT_ACCEL_ON_DELAY_LENGTH    2
#define MPU6050_DETECT_FF_COUNT_BIT             3
#define MPU6050_DETECT_FF_COUNT_LENGTH          2
#define MPU6050_DETECT_MOT_COUNT_BIT            1
#define MPU6050_DETECT_MOT_COUNT_LENGTH         2

#define MPU6050_DETECT_DECREMENT_RESET  0x0
#define MPU6050_DETECT_DECREMENT_1      0x1
#define MPU6050_DETECT_DECREMENT_2      0x2
#define MPU6050_DETECT_DECREMENT_4      0x3

#define MPU6050_USERCTRL_DMP_EN_BIT             7
#define MPU6050_USERCTRL_FIFO_EN_BIT            6
#define MPU6050_USERCTRL_I2C_MST_EN_BIT         5
#define MPU6050_USERCTRL_I2C_IF_DIS_BIT         4
#define MPU6050_USERCTRL_DMP_RESET_BIT          3
#define MPU6050_USERCTRL_FIFO_RESET_BIT         2
#define MPU6050_USERCTRL_I2C_MST_RESET_BIT      1
#define MPU6050_USERCTRL_SIG_COND_RESET_BIT     0

#define MPU6050_PWR1_DEVICE_RESET_BIT   7
#define MPU6050_PWR1_SLEEP_BIT          6
#define MPU6050_PWR1_CYCLE_BIT          5
#define MPU6050_PWR1_TEMP_DIS_BIT       3
#define MPU6050_PWR1_CLKSEL_BIT         2
#define MPU6050_PWR1_CLKSEL_LENGTH      3

#define MPU6050_CLOCK_INTERNAL          0x00
#define MPU6050_CLOCK_PLL_XGYRO         0x01
#define MPU6050_CLOCK_PLL_YGYRO         0x02
#define MPU6050_CLOCK_PLL_ZGYRO         0x03
#define MPU6050_CLOCK_PLL_EXT32K        0x04
#define MPU6050_CLOCK_PLL_EXT19M        0x05
#define MPU6050_CLOCK_KEEP_RESET        0x07

#define MPU6050_PWR2_LP_WAKE_CTRL_BIT       7
#define MPU6050_PWR2_LP_WAKE_CTRL_LENGTH    2
#define MPU6050_PWR2_STBY_XA_BIT            5
#define MPU6050_PWR2_STBY_YA_BIT            4
#define MPU6050_PWR2_STBY_ZA_BIT            3
#define MPU6050_PWR2_STBY_XG_BIT            2
#define MPU6050_PWR2_STBY_YG_BIT            1
#define MPU6050_PWR2_STBY_ZG_BIT            0

#define MPU6050_WAKE_FREQ_1P25      0x0
#define MPU6050_WAKE_FREQ_2P5       0x1
#define MPU6050_WAKE_FREQ_5         0x2
#define MPU6050_WAKE_FREQ_10        0x3

#define MPU6050_BANKSEL_PRFTCH_EN_BIT       6
#define MPU6050_BANKSEL_CFG_USER_BANK_BIT   5
#define MPU6050_BANKSEL_MEM_SEL_BIT         4
#define MPU6050_BANKSEL_MEM_SEL_LENGTH      5

#define MPU6050_WHO_AM_I_BIT        6
#define MPU6050_WHO_AM_I_LENGTH     6

#define MPU6050_DMP_MEMORY_BANKS        8
#define MPU6050_DMP_MEMORY_BANK_SIZE    256
#define MPU6050_DMP_MEMORY_CHUNK_SIZE   16

// note: DMP code memory blocks defined at end of header file

void pru_mpu6050_driver_Initialize();
uint8_t pru_mpu6050_driver_TestConnection();

// AUX_VDDIO register
uint8_t pru_mpu6050_driver_GetAuxVDDIOLevel();
void pru_mpu6050_driver_SetAuxVDDIOLevel(uint8_t level);

// SMPLRT_DIV register
uint8_t pru_mpu6050_driver_GetRate();
void pru_mpu6050_driver_SetRate(uint8_t rate);

// CONFIG register
uint8_t pru_mpu6050_driver_GetExternalFrameSync();
void pru_mpu6050_driver_SetExternalFrameSync(uint8_t sync);
uint8_t pru_mpu6050_driver_GetDLPFMode();
void pru_mpu6050_driver_SetDLPFMode(uint8_t bandwidth);

// GYRO_CONFIG register
uint8_t pru_mpu6050_driver_GetFullScaleGyroRange();
void pru_mpu6050_driver_SetFullScaleGyroRange(uint8_t range);

// ACCEL_CONFIG register
uint8_t pru_mpu6050_driver_GetAccelXSelfTest();
void pru_mpu6050_driver_SetAccelXSelfTest(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetAccelYSelfTest();
void pru_mpu6050_driver_SetAccelYSelfTest(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetAccelZSelfTest();
void pru_mpu6050_driver_SetAccelZSelfTest(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetFullScaleAccelRange();
void pru_mpu6050_driver_SetFullScaleAccelRange(uint8_t range);
uint8_t pru_mpu6050_driver_GetDHPFMode();
void pru_mpu6050_driver_SetDHPFMode(uint8_t mode);

// FF_THR register
uint8_t pru_mpu6050_driver_GetFreefallDetectionThreshold();
void pru_mpu6050_driver_SetFreefallDetectionThreshold(uint8_t threshold);

// FF_DUR register
uint8_t pru_mpu6050_driver_GetFreefallDetectionDuration();
void pru_mpu6050_driver_SetFreefallDetectionDuration(uint8_t duration);

// MOT_THR register
uint8_t pru_mpu6050_driver_GetMotionDetectionThreshold();
void pru_mpu6050_driver_SetMotionDetectionThreshold(uint8_t threshold);

// MOT_DUR register
uint8_t pru_mpu6050_driver_GetMotionDetectionDuration();
void pru_mpu6050_driver_SetMotionDetectionDuration(uint8_t duration);

// ZRMOT_THR register
uint8_t pru_mpu6050_driver_GetZeroMotionDetectionThreshold();
void pru_mpu6050_driver_SetZeroMotionDetectionThreshold(uint8_t threshold);

// ZRMOT_DUR register
uint8_t pru_mpu6050_driver_GetZeroMotionDetectionDuration();
void pru_mpu6050_driver_SetZeroMotionDetectionDuration(uint8_t duration);

// FIFO_EN register
uint8_t pru_mpu6050_driver_GetTempFIFOEnabled();
void pru_mpu6050_driver_SetTempFIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetXGyroFIFOEnabled();
void pru_mpu6050_driver_SetXGyroFIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetYGyroFIFOEnabled();
void pru_mpu6050_driver_SetYGyroFIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetZGyroFIFOEnabled();
void pru_mpu6050_driver_SetZGyroFIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetAccelFIFOEnabled();
void pru_mpu6050_driver_SetAccelFIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlave2FIFOEnabled();
void pru_mpu6050_driver_SetSlave2FIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlave1FIFOEnabled();
void pru_mpu6050_driver_SetSlave1FIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlave0FIFOEnabled();
void pru_mpu6050_driver_SetSlave0FIFOEnabled(uint8_t enabled);

// I2C_MST_CTRL register
uint8_t pru_mpu6050_driver_GetMultiMasterEnabled();
void pru_mpu6050_driver_SetMultiMasterEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetWaitForExternalSensorEnabled();
void pru_mpu6050_driver_SetWaitForExternalSensorEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlave3FIFOEnabled();
void pru_mpu6050_driver_SetSlave3FIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlaveReadWriteTransitionEnabled();
void pru_mpu6050_driver_SetSlaveReadWriteTransitionEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetMasterClockSpeed();
void pru_mpu6050_driver_SetMasterClockSpeed(uint8_t speed);

// I2C_SLV* registers (Slave 0-3)
uint8_t pru_mpu6050_driver_GetSlaveAddress(uint8_t num);
void pru_mpu6050_driver_SetSlaveAddress(uint8_t num, uint8_t address);
uint8_t pru_mpu6050_driver_GetSlaveRegister(uint8_t num);
void pru_mpu6050_driver_SetSlaveRegister(uint8_t num, uint8_t reg);
uint8_t pru_mpu6050_driver_GetSlaveEnabled(uint8_t num);
void pru_mpu6050_driver_SetSlaveEnabled(uint8_t num, uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlaveWordByteSwap(uint8_t num);
void pru_mpu6050_driver_SetSlaveWordByteSwap(uint8_t num, uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlaveWriteMode(uint8_t num);
void pru_mpu6050_driver_SetSlaveWriteMode(uint8_t num, uint8_t mode);
uint8_t pru_mpu6050_driver_GetSlaveWordGroupOffset(uint8_t num);
void pru_mpu6050_driver_SetSlaveWordGroupOffset(uint8_t num, uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlaveDataLength(uint8_t num);
void pru_mpu6050_driver_SetSlaveDataLength(uint8_t num, uint8_t length);

// I2C_SLV* registers (Slave 4)
uint8_t pru_mpu6050_driver_GetSlave4Address();
void pru_mpu6050_driver_SetSlave4Address(uint8_t address);
uint8_t pru_mpu6050_driver_GetSlave4Register();
void pru_mpu6050_driver_SetSlave4Register(uint8_t reg);
void pru_mpu6050_driver_SetSlave4OutputByte(uint8_t data);
uint8_t pru_mpu6050_driver_GetSlave4Enabled();
void pru_mpu6050_driver_SetSlave4Enabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlave4InterruptEnabled();
void pru_mpu6050_driver_SetSlave4InterruptEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlave4WriteMode();
void pru_mpu6050_driver_SetSlave4WriteMode(uint8_t mode);
uint8_t pru_mpu6050_driver_GetSlave4MasterDelay();
void pru_mpu6050_driver_SetSlave4MasterDelay(uint8_t delay);
uint8_t pru_mpu6050_driver_GetSlate4InputByte();

// I2C_MST_STATUS register
uint8_t pru_mpu6050_driver_GetPassthroughStatus();
uint8_t pru_mpu6050_driver_GetSlave4IsDone();
uint8_t pru_mpu6050_driver_GetLostArbitration();
uint8_t pru_mpu6050_driver_GetSlave4Nack();
uint8_t pru_mpu6050_driver_GetSlave3Nack();
uint8_t pru_mpu6050_driver_GetSlave2Nack();
uint8_t pru_mpu6050_driver_GetSlave1Nack();
uint8_t pru_mpu6050_driver_GetSlave0Nack();

// INT_PIN_CFG register
uint8_t pru_mpu6050_driver_GetInterruptMode();
void pru_mpu6050_driver_SetInterruptMode(uint8_t mode);
uint8_t pru_mpu6050_driver_GetInterruptDrive();
void pru_mpu6050_driver_SetInterruptDrive(uint8_t drive);
uint8_t pru_mpu6050_driver_GetInterruptLatch();
void pru_mpu6050_driver_SetInterruptLatch(uint8_t latch);
uint8_t pru_mpu6050_driver_GetInterruptLatchClear();
void pru_mpu6050_driver_SetInterruptLatchClear(uint8_t clear);
uint8_t pru_mpu6050_driver_GetFSyncInterruptLevel();
void pru_mpu6050_driver_SetFSyncInterruptLevel(uint8_t level);
uint8_t pru_mpu6050_driver_GetFSyncInterruptEnabled();
void pru_mpu6050_driver_SetFSyncInterruptEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetI2CBypassEnabled();
void pru_mpu6050_driver_SetI2CBypassEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetClockOutputEnabled();
void pru_mpu6050_driver_SetClockOutputEnabled(uint8_t enabled);

// INT_ENABLE register
uint8_t pru_mpu6050_driver_GetIntEnabled();
void pru_mpu6050_driver_SetIntEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetIntFreefallEnabled();
void pru_mpu6050_driver_SetIntFreefallEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetIntMotionEnabled();
void pru_mpu6050_driver_SetIntMotionEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetIntZeroMotionEnabled();
void pru_mpu6050_driver_SetIntZeroMotionEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetIntFIFOBufferOverflowEnabled();
void pru_mpu6050_driver_SetIntFIFOBufferOverflowEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetIntI2CMasterEnabled();
void pru_mpu6050_driver_SetIntI2CMasterEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetIntDataReadyEnabled();
void pru_mpu6050_driver_SetIntDataReadyEnabled(uint8_t enabled);

// INT_STATUS register
uint8_t pru_mpu6050_driver_GetIntStatus();
uint8_t pru_mpu6050_driver_GetIntFreefallStatus();
uint8_t pru_mpu6050_driver_GetIntMotionStatus();
uint8_t pru_mpu6050_driver_GetIntZeroMotionStatus();
uint8_t pru_mpu6050_driver_GetIntFIFOBufferOverflowStatus();
uint8_t pru_mpu6050_driver_GetIntI2CMasterStatus();
uint8_t pru_mpu6050_driver_GetIntDataReadyStatus();

// ACCEL_*OUT_* registers
void pru_mpu6050_driver_GetMotion9(int16_t* ax, int16_t* ay, int16_t* az,
                                   int16_t* gx, int16_t* gy, int16_t* gz,
                                   int16_t* mx, int16_t* my, int16_t* mz);
void pru_mpu6050_driver_GetMotion6(int16_t* ax, int16_t* ay, int16_t* az,
                                   int16_t* gx, int16_t* gy, int16_t* gz);
void pru_mpu6050_driver_GetAcceleration(int16_t* x, int16_t* y, int16_t* z);
int16_t pru_mpu6050_driver_GetAccelerationX();
int16_t pru_mpu6050_driver_GetAccelerationY();
int16_t pru_mpu6050_driver_GetAccelerationZ();

// TEMP_OUT_* registers
int16_t pru_mpu6050_driver_GetTemperature();

// GYRO_*OUT_* registers
void pru_mpu6050_driver_GetRotation(int16_t* x, int16_t* y, int16_t* z);
int16_t pru_mpu6050_driver_GetRotationX();
int16_t pru_mpu6050_driver_GetRotationY();
int16_t pru_mpu6050_driver_GetRotationZ();

// EXT_SENS_DATA_* registers
uint8_t pru_mpu6050_driver_GetExternalSensorByte(int position);
uint16_t pru_mpu6050_driver_GetExternalSensorWord(int position);
uint32_t pru_mpu6050_driver_GetExternalSensorDWord(int position);

// MOT_DETECT_STATUS register
uint8_t pru_mpu6050_driver_GetXNegMotionDetected();
uint8_t pru_mpu6050_driver_GetXPosMotionDetected();
uint8_t pru_mpu6050_driver_GetYNegMotionDetected();
uint8_t pru_mpu6050_driver_GetYPosMotionDetected();
uint8_t pru_mpu6050_driver_GetZNegMotionDetected();
uint8_t pru_mpu6050_driver_GetZPosMotionDetected();
uint8_t pru_mpu6050_driver_GetZeroMotionDetected();

// I2C_SLV*_DO register
void pru_mpu6050_driver_SetSlaveOutputByte(uint8_t num, uint8_t data);

// I2C_MST_DELAY_CTRL register
uint8_t pru_mpu6050_driver_GetExternalShadowDelayEnabled();
void pru_mpu6050_driver_SetExternalShadowDelayEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetSlaveDelayEnabled(uint8_t num);
void pru_mpu6050_driver_SetSlaveDelayEnabled(uint8_t num, uint8_t enabled);

// SIGNAL_PATH_RESET register
void pru_mpu6050_driver_ResetGyroscopePath();
void pru_mpu6050_driver_ResetAccelerometerPath();
void pru_mpu6050_driver_ResetTemperaturePath();

// MOT_DETECT_CTRL register
uint8_t pru_mpu6050_driver_GetAccelerometerPowerOnDelay();
void pru_mpu6050_driver_SetAccelerometerPowerOnDelay(uint8_t delay);
uint8_t pru_mpu6050_driver_GetFreefallDetectionCounterDecrement();
void pru_mpu6050_driver_SetFreefallDetectionCounterDecrement(uint8_t decrement);
uint8_t pru_mpu6050_driver_GetMotionDetectionCounterDecrement();
void pru_mpu6050_driver_SetMotionDetectionCounterDecrement(uint8_t decrement);

// USER_CTRL register
uint8_t pru_mpu6050_driver_GetFIFOEnabled();
void pru_mpu6050_driver_SetFIFOEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetI2CMasterModeEnabled();
void pru_mpu6050_driver_SetI2CMasterModeEnabled(uint8_t enabled);
void pru_mpu6050_driver_SwitchSPIEnabled(uint8_t enabled);
void pru_mpu6050_driver_ResetFIFO();
void pru_mpu6050_driver_ResetI2CMaster();
void pru_mpu6050_driver_ResetSensors();

// PWR_MGMT_1 register
void pru_mpu6050_driver_Reset();
uint8_t pru_mpu6050_driver_GetSleepEnabled();
void pru_mpu6050_driver_SetSleepEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetWakeCycleEnabled();
void pru_mpu6050_driver_SetWakeCycleEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetTempSensorEnabled();
void pru_mpu6050_driver_SetTempSensorEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetClockSource();
void pru_mpu6050_driver_SetClockSource(uint8_t source);

// PWR_MGMT_2 register
uint8_t pru_mpu6050_driver_GetWakeFrequency();
void pru_mpu6050_driver_SetWakeFrequency(uint8_t frequency);
uint8_t pru_mpu6050_driver_GetStandbyXAccelEnabled();
void pru_mpu6050_driver_SetStandbyXAccelEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetStandbyYAccelEnabled();
void pru_mpu6050_driver_SetStandbyYAccelEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetStandbyZAccelEnabled();
void pru_mpu6050_driver_SetStandbyZAccelEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetStandbyXGyroEnabled();
void pru_mpu6050_driver_SetStandbyXGyroEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetStandbyYGyroEnabled();
void pru_mpu6050_driver_SetStandbyYGyroEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetStandbyZGyroEnabled();
void pru_mpu6050_driver_SetStandbyZGyroEnabled(uint8_t enabled);

// FIFO_COUNT_* registers
uint16_t pru_mpu6050_driver_GetFIFOCount();

// FIFO_R_W register
uint8_t pru_mpu6050_driver_GetFIFOByte();
void pru_mpu6050_driver_SetFIFOByte(uint8_t data);
void pru_mpu6050_driver_GetFIFOBytes(uint8_t *data, uint8_t length);

// WHO_AM_I register
uint8_t pru_mpu6050_driver_GetDeviceID();
void pru_mpu6050_driver_SetDeviceID(uint8_t id);

// ======== UNDOCUMENTED/DMP REGISTERS/METHODS ========

// XG_OFFS_TC register
uint8_t pru_mpu6050_driver_GetOTPBankValid();
void pru_mpu6050_driver_SetOTPBankValid(uint8_t enabled);
int8_t pru_mpu6050_driver_GetXGyroOffset();
void pru_mpu6050_driver_SetXGyroOffset(int8_t offset);

// YG_OFFS_TC register
int8_t pru_mpu6050_driver_GetYGyroOffset();
void pru_mpu6050_driver_SetYGyroOffset(int8_t offset);

// ZG_OFFS_TC register
int8_t pru_mpu6050_driver_GetZGyroOffset();
void pru_mpu6050_driver_SetZGyroOffset(int8_t offset);

// X_FINE_GAIN register
int8_t pru_mpu6050_driver_GetXFineGain();
void pru_mpu6050_driver_SetXFineGain(int8_t gain);

// Y_FINE_GAIN register
int8_t pru_mpu6050_driver_GetYFineGain();
void pru_mpu6050_driver_SetYFineGain(int8_t gain);

// Z_FINE_GAIN register
int8_t pru_mpu6050_driver_GetZFineGain();
void pru_mpu6050_driver_SetZFineGain(int8_t gain);

// XA_OFFS_* registers
int16_t pru_mpu6050_driver_GetXAccelOffset();
void pru_mpu6050_driver_SetXAccelOffset(int16_t offset);

// YA_OFFS_* register
int16_t pru_mpu6050_driver_GetYAccelOffset();
void pru_mpu6050_driver_SetYAccelOffset(int16_t offset);

// ZA_OFFS_* register
int16_t pru_mpu6050_driver_GetZAccelOffset();
void pru_mpu6050_driver_SetZAccelOffset(int16_t offset);

// XG_OFFS_USR* registers
int16_t pru_mpu6050_driver_GetXGyroOffsetUser();
void pru_mpu6050_driver_SetXGyroOffsetUser(int16_t offset);

// YG_OFFS_USR* register
int16_t pru_mpu6050_driver_GetYGyroOffsetUser();
void pru_mpu6050_driver_SetYGyroOffsetUser(int16_t offset);

// ZG_OFFS_USR* register
int16_t pru_mpu6050_driver_GetZGyroOffsetUser();
void pru_mpu6050_driver_SetZGyroOffsetUser(int16_t offset);

// INT_ENABLE register (DMP functions)
uint8_t pru_mpu6050_driver_GetIntPLLReadyEnabled();
void pru_mpu6050_driver_SetIntPLLReadyEnabled(uint8_t enabled);
uint8_t pru_mpu6050_driver_GetIntDMPEnabled();
void pru_mpu6050_driver_SetIntDMPEnabled(uint8_t enabled);

// DMP_INT_STATUS
uint8_t pru_mpu6050_driver_GetDMPInt5Status();
uint8_t pru_mpu6050_driver_GetDMPInt4Status();
uint8_t pru_mpu6050_driver_GetDMPInt3Status();
uint8_t pru_mpu6050_driver_GetDMPInt2Status();
uint8_t pru_mpu6050_driver_GetDMPInt1Status();
uint8_t pru_mpu6050_driver_GetDMPInt0Status();

// INT_STATUS register (DMP functions)
uint8_t pru_mpu6050_driver_GetIntPLLReadyStatus();
uint8_t pru_mpu6050_driver_GetIntDMPStatus();

// USER_CTRL register (DMP functions)
uint8_t pru_mpu6050_driver_GetDMPEnabled();
void pru_mpu6050_driver_SetDMPEnabled(uint8_t enabled);
void pru_mpu6050_driver_ResetDMP();

/********************************************************************************************
 * D M P  M E T H O D S
 ********************************************************************************************/

// DMP_CFG_1 register
uint8_t pru_mpu6050_driver_GetDMPConfig1();
void pru_mpu6050_driver_SetDMPConfig1(uint8_t config);

// DMP_CFG_2 register
uint8_t pru_mpu6050_driver_GetDMPConfig2();
void pru_mpu6050_driver_SetDMPConfig2(uint8_t config);

uint8_t pru_mpu6050_driver_DmpPacketAvailable();

uint8_t pru_mpu6050_driver_DmpSetFIFORate(uint8_t fifoRate);
uint8_t pru_mpu6050_driver_DmpGetFIFORate();
uint8_t pru_mpu6050_driver_DmpGetSampleStepSizeMS();
uint8_t pru_mpu6050_driver_DmpGetSampleFrequency();
int32_t pru_mpu6050_driver_DmpDecodeTemperature(int8_t tempReg);

// Register callbacks after a packet of FIFO data is processed
//uint8_t dmpRegisterFIFORateProcess(inv_obj_func func, int16_t priority);
//uint8_t dmpUnregisterFIFORateProcess(inv_obj_func func);
uint8_t pru_mpu6050_driver_DmpRunFIFORateProcesses();

// Setup FIFO for various output
uint8_t pru_mpu6050_driver_DmpSendQuaternion(uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendGyro(uint_fast16_t elements,
                                       uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendAccel(uint_fast16_t elements,
                                        uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendLinearAccel(uint_fast16_t elements,
                                              uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendLinearAccelInWorld(uint_fast16_t elements,
                                                     uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendControlData(uint_fast16_t elements,
                                              uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendSensorData(uint_fast16_t elements,
                                             uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendExternalSensorData(uint_fast16_t elements,
                                                     uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendGravity(uint_fast16_t elements,
                                          uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendPacketNumber(uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendQuantizedAccel(uint_fast16_t elements,
                                                 uint_fast16_t accuracy);
uint8_t pru_mpu6050_driver_DmpSendEIS(uint_fast16_t elements,
                                      uint_fast16_t accuracy);

// Get Fixed Point data from FIFO
uint8_t pru_mpu6050_driver_DmpGetAccel32(int32_t *data, const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetAccel16(int16_t *data, const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetQuaternion32(int32_t *data,
                                              const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetQuaternion16(int16_t *data,
                                              const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGet6AxisQuaternion32(int32_t *data,
                                                   const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGet6AxisQuaternion16(int16_t *data,
                                                   const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetRelativeQuaternion32(int32_t *data,
                                                      const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetRelativeQuaternion16(int16_t *data,
                                                      const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetGyro32(int32_t *data, const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetGyro16(int16_t *data, const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetMag(int16_t *data, const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpSetLinearAccelFilterCoefficient(float coef);
uint8_t pru_mpu6050_driver_DmpGetLinearAccel32(int32_t *data,
                                               const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetLinearAccel16(int16_t *data,
                                               const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetLinearAccelInWorld32(int32_t *data,
                                                      const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetLinearAccelInWorld16(int16_t *data,
                                                      const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetGyroAndAccelSensor32(int32_t *data,
                                                      const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetGyroAndAccelSensor16(int16_t *data,
                                                      const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetGyroSensor32(int32_t *data,
                                              const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetGyroSensor16(int16_t *data,
                                              const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetControlData(int32_t *data,
                                             const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetTemperature(int32_t *data,
                                             const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetGravity32(int32_t *data,
                                           const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetGravity16(int16_t *data,
                                           const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetUnquantizedAccel32(int32_t *data,
                                                    const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetUnquantizedAccel16(int16_t *data,
                                                    const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetQuantizedAccel32(int32_t *data,
                                                  const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetQuantizedAccel16(int16_t *data,
                                                  const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetExternalSensorData(int32_t *data,
                                                    uint16_t size,
                                                    const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetEIS(int32_t *data, const uint8_t* packet);

// Get Floating Point data from FIFO
uint8_t pru_mpu6050_driver_DmpGetAccelFloat(float *data, const uint8_t* packet);
uint8_t pru_mpu6050_driver_DmpGetQuaternionFloat(float *data,
                                                 const uint8_t* packet);

uint8_t pru_mpu6050_driver_DmpProcessFIFOPacket(const unsigned char *dmpData);
uint8_t pru_mpu6050_driver_DmpReadAndProcessFIFOPacket(uint8_t numPackets,
                                                       uint8_t *processed);

uint8_t pru_mpu6050_driver_DmpSetFIFOProcessedCallback(void (*func)(void));

uint8_t pru_mpu6050_driver_DmpInitFIFOParam();
uint8_t pru_mpu6050_driver_DmpCloseFIFO();
uint8_t pru_mpu6050_driver_DmpSetGyroDataSource(uint8_t source);
uint8_t pru_mpu6050_driver_DmpDecodeQuantizedAccel();
uint32_t pru_mpu6050_driver_DmpGetGyroSumOfSquare();
uint32_t pru_mpu6050_driver_DmpGetAccelSumOfSquare();
void pru_mpu6050_driver_DmpOverrideQuaternion(long *q);
uint16_t pru_mpu6050_driver_DmpGetFIFOPacketSize();

#endif /* _MPU6050_H_ */
