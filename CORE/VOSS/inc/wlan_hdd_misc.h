/*
 * Copyright (c) 2012-2016,2019 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

#ifndef WLAN_HDD_MISC_H
#define WLAN_HDD_MISC_H

/*
 * If MULTI_IF_NAME is defined, then prepend MULTI_IF_NAME to the filename
 * to prevent name conflicts when loading multiple instances of the driver.
 */
#ifdef MULTI_IF_NAME
#define PREFIX MULTI_IF_NAME "/"
#define PREFIX_QCA9377  MULTI_IF_NAME "/"
#define PREFIX_QCA6174  MULTI_IF_NAME "/"
#else
#define PREFIX ""
#define PREFIX_QCA9377 "qca9377/"
#define PREFIX_QCA6174 "qca6174/"
#endif

#ifdef MSM_PLATFORM
#define WLAN_INI_FILE              "wlan/qca_cld/" PREFIX "WCNSS_qcom_cfg.ini"
#define WLAN_CFG_FILE              "wlan/qca_cld/" PREFIX "WCNSS_cfg.dat"
#define WLAN_MAC_FILE              "wlan/qca_cld/" PREFIX "wlan_mac.bin"
#else

#ifndef FEATURE_LARGE_PREALLOC
#define WLAN_INI_FILE              "wlan/" PREFIX "qcom_cfg.ini"
#define QCA9377_INI_FILE           "wlan/" PREFIX_QCA9377 "qcom_cfg.ini"
#define QCA6174_INI_FILE           "wlan/" PREFIX_QCA6174 "qcom_cfg.ini"
#define WLAN_CFG_FILE              "wlan/" PREFIX "cfg.dat"
#define WLAN_MAC_FILE              "wlan/" PREFIX "wlan_mac.bin"
#else
#define WLAN_INI_FILE              "wlan/qcom_cfg.ini"
#define WLAN_CFG_FILE              "wlan/cfg.dat"
#define WLAN_MAC_FILE              "wlan/wlan_mac.bin"
#endif

#endif // MSM_PLATFORM

VOS_STATUS hdd_get_cfg_file_size(v_VOID_t *pCtx, char *pFileName, v_SIZE_t *pBufSize);

VOS_STATUS hdd_read_cfg_file(v_VOID_t *pCtx, char *pFileName, v_VOID_t *pBuffer, v_SIZE_t *pBufSize);

tVOS_CONCURRENCY_MODE hdd_get_concurrency_mode ( void );

#endif /* WLAN_HDD_MISC_H */
