/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file      DIL_Datatypes.h
 * \brief     Defines DIL related data types
 * \author    Ratnadip Choudhury
 * \copyright Copyright (c) 2011, Robert Bosch Engineering and Business Solutions. All rights reserved.
 *
 * Defines DIL related data types
 */

#pragma once

/* C++ includes */
#include <string>

/* Project includes */
#include "../Include/BaseDefs.h"

using namespace std;

#define NO_SELECTION_HI 0xCDCD

#define CAN_MONITOR_NODE _T("CAN_MONITOR")
const int CAN_MONITOR_NODE_INDEX = 0;
const int CAN_MONITOR_CLIENT_ID  = 1;

#define J1939_MONITOR_NODE _T("J1939_MONITOR")
const UINT64 J1939_ECU_NAME     = 0x8000000000000001;

const BYTE MSGBUF_ADD = 0x1;
const BYTE MSGBUF_CLEAR = 0x0;

enum ECONTR_STATUS
{
    RESET_STATE = 0,    // reset
    INITIALISED,        // stopped / initialized
    WAITING,            // started / waiting for startup completion
    NORMAL_ACTIVE,      // started / normal active (running)
    NORMAL_PASSIVE,     // started / normal passiv
    NOT_DEFINED,        // started / halt mode
};

enum ECONTR_PARAM
{
    NUMBER_HW = 0,
    NUMBER_CONNECTED_HW,
    PEAK_ERR_CNT,
    DRIVER_STATUS,
    ERR_CNT,
    HW_MODE,
    CNTR_STATUS,
    CON_TEST,
};

//----------------------------------------------------------------------------
// declaration of FlexRay status message
//----------------------------------------------------------------------------

typedef struct struct_STATUSMSG
{
    unsigned short wControllerStatus;    // Current controller state
    unsigned long  dwStatusInfoFlags;    // Flagfield of status information (UCI_FLXSTSINFO_???)
} s_STATUSMSG, *ps_STATUSMSG;

enum
{
    DRIVER_CAN_STUB = 0,
    DRIVER_CAN_PEAK_USB,
    DRIVER_CAN_ICS_NEOVI,
    DRIVER_CAN_ETAS_BOA,
    DRIVER_CAN_ETAS_ES581,
    DRIVER_CAN_VECTOR_XL,
    DRIVER_CAN_KVASER_CAN,
    DRIVER_CAN_MHS,
    DIL_TOTAL,          // Its value must be <= MAX_DILS
    DAL_NONE            = ~0x0
};

typedef enum FILTER_TYPE
{
    PASS_FILTER = 0,
    STOP_FILTER,
} FILTER_TYPE;

typedef enum TXMODE
{
    SINGLE_SHOT = 0,
    CONTINOUS,
} TXMODE;

//#define  MAX_CHAR_SHORT       128
//#define  MAX_CHAR_LONG        512
#define  MAX_CHAR             1024

class INTERFACE_HW
{
public:
    unsigned long  m_dwIdInterface;
    unsigned long  m_dwVendor;
    unsigned char  m_bytNetworkID;
    string         m_acNameInterface;
    string         m_acDescription;
    string         m_acDeviceName;
} ;

typedef INTERFACE_HW INTERFACE_HW_LIST[defNO_OF_CHANNELS];

class VERSIONINFO
{
public:
    string     m_acDIL;
    string     m_acController;
    string     m_acDriver;
};

class DILINFO
{
public:
    string         m_acName;
    unsigned long  m_dwDriverID;
    unsigned int   m_ResourceID;
};

const int MAX_DILS = 16;
typedef DILINFO DILLIST[MAX_DILS];
