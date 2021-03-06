/*! @file : sdk_pph_ec25au.h
 * @author  Ernesto Andres Rincon Cruz
 * @version 1.0.0
 * @date    23/01/2021
 * @brief   Driver para modem EC25AU
 * @details
 *
 */
#ifndef SDK_PPH_EC25AU_H_
#define SDK_PPH_EC25AU_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "sdk_hal_uart0.h"

/*!
 * @addtogroup PPH
 * @{
 */
/*!
 * @addtogroup EC25AU
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
enum _ec25_lista_comandos_at {
	kAT = 0,
	kATI,
	kAT_CPIN,
	kAT_QCFG_CONFIG1,
	kAT_QCFG_CONFIG2,
	kAT_QCSQ,
	kAT_CREG,
	kAT_CGREG,
	kAT_CEREG,
	kAT_CGDCONT,
	kAT_QMTOPEN,
	kAT_QMTCONN,
	kAT_QMTPUB_T_H,
	kAT_MQTT_MSJ_T_H,
	kAT_CFUN_0,
	kAT_CFUN_1,
};

enum _fsm_ec25_state{
	kFSM_INICIO=0,
	kFSM_ENVIANDO_AT,
	kFSM_ENVIANDO_ATI,
	kFSM_ENVIANDO_CPIN,
	kFSM_ENVIANDO_QCFG_CONFIG1,
	kFSM_ENVIANDO_QCFG_CONFIG2,
	kFSM_ENVIANDO_QCSQ,
	kFSM_ENVIANDO_CREG,
	kFSM_ENVIANDO_CGREG,
	kFSM_ENVIANDO_CEREG,
	kFSM_ENVIANDO_CGDCONT,
	kFSM_ENVIANDO_QMTOPEN,
	kFSM_ENVIANDO_QMTCONN,
	kFSM_ENVIANDO_QMTPUB_T_H,
	kFSM_ENVIANDO_MQTT_MSJ_T_H,
	kFSM_ENVIANDO_CFUN_0,
	kFSM_ENVIANDO_CFUN_1,
	kFSM_ESPERANDO_RESPUESTA,
	kFSM_RESULTADO_ERROR,
	kFSM_RESULTADO_EXITOSO,
	kFSM_PROCESANDO_RESPUESTA,
};

#define EC25_TIEMPO_MAXIMO_ESPERA	5		//Tiempo maximo que espera modem por respuesta
#define EC25_RSSI_MINIMO_ACEPTADO	20		//RSSI minimo aceptado segun tabla de fabricante
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/
status_t ec25Inicializacion(void);
status_t ec25InicializarMQTT(void);
status_t ec25sensor(float peso);
uint8_t ec25Polling(void);

/** @} */ // end of X group
/** @} */ // end of X group

#endif /* SDK_PPH_EC25AU_H_ */
