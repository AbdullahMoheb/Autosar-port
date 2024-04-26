 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Mohamed Tarek - Abdullah Moheb
 *
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#include "Common_Macros.h"
#include "Std_Types.h"
#include "Port_Cfg.h"


 /* ID for Company; example My ID = 1234 :) */
#define PORT_VENDOR_ID    (1234U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/* Module Version 1.0.0  */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/* AUTOSAR Version 4.0.3 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/* External PostBuild structures to be used in Port_Init() API */


/*******************************************************************************
 *                              DET errors                                     *
 *******************************************************************************/
#define PORT_E_PARAM_PIN                    (uint8)0x0A

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE       (uint8)0x0B

/* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG                 (uint8)0x0C

/* API Port_SetPinMode service called when Port Pin Mode passed not valid */
#define PORT_E_PARAM_INVALID_MODE           (uint8)0x0D

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE            (uint8)0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT                       (uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                (uint8)0x10


/*******************************************************************************
 *                              API Services                                   *
 *******************************************************************************/


#define PORT_INIT_SID                          (uint8)0x00

/* Service ID for Port Set Channel direction */
#if (PORT_SET_PIN_DIRECTION_API  == STD_ON)
#define PORT_SET_PIN_DIRECTION_SID             (uint8)0x01
#endif

/* Service ID for Port Refersh Channel direction */
#define PORT_REFRESH_PIN_DIRECTION_SID         (uint8)0x02

/* Service ID for Port GetVersionInfo  */
#if (PORT_VERSION_INFO_API == STD_ON)
#define PORT_GET_VERSION_INFO_SID                   (uint8)0x03
#endif

/* Service ID for Port Set Channel Mode */
#if (PORT_SET_PIN_MODE_API == STD_ON)
#define PORT_SET_PIN_MODE_SID                   (uint8)0x04
#endif

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Port_PinType for PORT APIs */
typedef uint8 Port_PinType;

/* Type definition for Port_PinModeType for PORT APIs */
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}Port_PinDirection;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;


/* Description: Enum to hold level value for PIN */
typedef enum
{
    LEVEL_LOW,LEVEL_HIGH
}Port_Pin_Level_Value;

/* Description: Enum to hold initial mode for PIN */
typedef enum
{
        MODE_ADC,
        MODE_Alternate1,
        MODE_Alternate2,
        MODE_Alternate3,
        MODE_Alternate4,
        MODE_Alternate5,
        MODE_Alternate6,
        MODE_Alternate7,
        MODE_Alternate8,
        MODE_Alternate9,
        MODE_DIO,
}Port_Pin_Initial_Mode;

/* Description: Structure to configure each individual PIN:
 *  1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *  2. the number of the pin in the PORT.
 *  3. the direction of pin --> INPUT or OUTPUT
 *  4. the internal resistor --> Disable, Pull up or Pull down
 *  5. port pin initial level value --> high, low
 *  6. port pin initial mode --> adc ,alt(1-->9),Dio mode
 */

typedef struct 
{
  //  Port_PinType PinID;
    uint8 port_num;
    uint8 pin_num;
    Port_PinDirection direction;
    Port_InternalResistor resistor;
    Port_Pin_Level_Value initial_value;   /* LEVEL_LOW,LEVEL_HIGH   */
    Port_Pin_Initial_Mode initial_mode;   /* Ex: PORT_PIN_MODE_DIO  */
    uint8 pin_dir_changeable;           /* STD_ON,STD_OFF  */
    uint8 pin_mode_changeable;          /* STD_ON,STD_OFF  */
}Port_ConfigPin;

/* Data Structure required for initializing the Dio Driver */
typedef struct Port_ConfigType
{
    Port_ConfigPin Pin[PORT_CONFIGURED_PINS];
} Port_ConfigType;

extern const Port_ConfigType Port_Configuration;

/* Port initialization status */
#define PORT_INITIALIZED                        (1U)
#define PORT_NOT_INITIALIZED                    (0U)

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_SetupGpioPin
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Setup the internal resistor for i/p pin
************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr );

/*
Service Name Port_SetPinDirection
    Syntax void Port_SetPinDirection (
    Port_PinType Pin,
    Port_PinDirectionType Direction  )
Service ID [hex] 0x01
Sync/Async Synchronous
Reentrancy Reentrant
Parameters (in) Pin Port Pin ID number
Direction Port Pin Direction
Parameters (inout) None
Parameters (out) None
Return value None
Description Sets the port pin direction
Available via Port.
 *
 */
#if (PORT_SET_PIN_DIRECTION == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirection Direction );
#endif

/*
Service Name Port_RefreshPortDirection
Syntax void Port_RefreshPortDirection (
void )
Service ID [hex] 0x02
Sync/Async Synchronous
Reentrancy Non Reentrant
Parameters (in) None
Parameters (inout) None
Parameters (out) None
Return value None
Description Refreshes port direction.
Available via Port.h

 */
void Port_RefreshPortDirection(void);


/*
Service Name Port_GetVersionInfo
Syntax void Port_GetVersionInfo (
Std_VersionInfoType* versioninfo )
Service ID [hex] 0x03
Sync/Async Synchronous
Reentrancy Reentrant
Parameters (in) None
Parameters (inout) None
Parameters (out) versioninfo Pointer to where to store the version information of this module.
Return value None
Description Returns the version information of this module.
Available via Port.h
 *
 */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif


/*
 * Service Name Port_SetPinMode
Syntax void Port_SetPinMode (
Port_PinType Pin,
Port_PinModeType Mode
)
Service ID [hex] 0x04
Sync/Async Synchronous
Reentrancy Reentrant
Parameters (in) Pin Port Pin ID number
Mode New Port Pin mode to be set on port pin.
Parameters (inout) None
Parameters (out) None
Return value None
Description Sets the port pin mode.
Available via Port.h
 *
 */
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif



#endif /* PORT_H */
