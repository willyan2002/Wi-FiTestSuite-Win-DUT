/****************************************************************************
 *  (c) Copyright 2007 Wi-Fi Alliance.  All Rights Reserved
 *
 *
 *  LICENSE
 *
 *  License is granted only to Wi-Fi Alliance members and designated
 *  contractors ($B!H(BAuthorized Licensees$B!I(B)..AN  Authorized Licensees are granted
 *  the non-exclusive, worldwide, limited right to use, copy, import, export
 *  and distribute this software:
 *  (i) solely for noncommercial applications and solely for testing Wi-Fi
 *  equipment; and
 *  (ii) solely for the purpose of embedding the software into Authorized
 *  Licensee$B!G(Bs proprietary equipment and software products for distribution to
 *  its customers under a license with at least the same restrictions as
 *  contained in this License, including, without limitation, the disclaimer of
 *  warranty and limitation of liability, below..AN  The distribution rights
 *  granted in clause
 *  (ii), above, include distribution to third party companies who will
 *  redistribute the Authorized Licensee$B!G(Bs product to their customers with or
 *  without such third party$B!G(Bs private label. Other than expressly granted
 *  herein, this License is not transferable or sublicensable, and it does not
 *  extend to and may not be used with non-Wi-Fi applications..AN  Wi-Fi Alliance
 *  reserves all rights not expressly granted herein..AN 
 *.AN 
 *  Except as specifically set forth above, commercial derivative works of
 *  this software or applications that use the Wi-Fi scripts generated by this
 *  software are NOT AUTHORIZED without specific prior written permission from
 *  Wi-Fi Alliance.
 *.AN 
 *  Non-Commercial derivative works of this software for internal use are
 *  authorized and are limited by the same restrictions; provided, however,
 *  that the Authorized Licensee shall provide Wi-Fi Alliance with a copy of
 *  such derivative works under a perpetual, payment-free license to use,
 *  modify, and distribute such derivative works for purposes of testing Wi-Fi
 *  equipment.
 *.AN 
 *  Neither the name of the author nor "Wi-Fi Alliance" may be used to endorse
 *  or promote products that are derived from or that use this software without
 *  specific prior written permission from Wi-Fi Alliance.
 *
 *  THIS SOFTWARE IS PROVIDED BY WI-FI ALLIANCE "AS IS" AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A.AN PARTICULAR PURPOSE,
 *  ARE DISCLAIMED. IN NO EVENT SHALL WI-FI ALLIANCE BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, THE COST OF PROCUREMENT OF SUBSTITUTE
 *  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE) ARISING IN ANY WAY OUT OF
 *  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ******************************************************************************
 */
/*
 *   Revision History: WINv03.00.00 - Simga 3.0 Release, supports TGn Program including WMM and WPA2
 */ 

#ifndef WFA_RSP_H
#define WFA_RSP_H

#ifdef WFA_WMM_VOICE
#define WFA_INFO_BUFSIZE       128   /* used to upload test data */
#else
#define WFA_INFO_BUFSIZE       128 
#endif

typedef struct _tg_ping_stop_resp
{
    int sendCnt;
    int repliedCnt;
} tgPingStopResp_t;

typedef struct ca_sta_get_ipconfig_resp
{

    int isDhcp;
	int ipTypeV6;
	char ipV6addr[WFA_IP_V6_ADDR_STR_LEN];
    char ipaddr[WFA_IP_ADDR_STR_LEN];
    char mask[WFA_IP_MASK_STR_LEN];
    char dns[WFA_MAX_DNS_NUM][WFA_IP_ADDR_STR_LEN];
} caStaGetIpConfigResp_t;

typedef struct ca_sta_get_stats_resp
{
   int status;
   int txFrames;
   int rxFrames;
   int txMulticast;
   int rxMulticast;
   int fcsErrors ;
   int txRetries;
} caStaGetStatsResp_t;

typedef struct ca_device_get_info_resp
{
   char vendor[16];
   char model[16];
   char version[16];
} caDeviceGetInfoResp_t;

typedef struct ca_sta_upload_resp
{
   short seqnum;
   short nbytes;
   char bytes[256]; 
} caStaUploadResp_t;

typedef struct ca_device_list_if_resp
{
   int status;
#define IF_80211   1
#define IF_ETH     2
   int iftype;
   
   char ifs[3][64];

} caDeviceListIFResp_t;

typedef struct ca_sta_cli_command_resp
{
   int status;
   short resFlag;
   char result[WFA_CLI_CMD_RESP_LEN]; 
} caStaCliCmdResp_t;

#ifdef WFA_P2P

typedef struct ca_P2p_sta_get_psk_resp
{
   char ssid[WFA_SSID_NAME_LEN];
   char passPhrase[WFA_PSK_PP_LEN];
} caP2pStaGetPskResp_t;

#endif


typedef struct dut_cmd_response
{
   int status;
   int streamId;
   union _cmdru
   {
       tgStats_t stats;
       tgPingStopResp_t pingStp;
       caStaGetIpConfigResp_t getIfconfig;
       caStaGetStatsResp_t ifStats;
       caDeviceGetInfoResp_t devInfo;
       caDeviceListIFResp_t ifList;
       caStaUploadResp_t  uld;
       char version[WFA_VERSION_LEN];
       char info[WFA_INFO_BUFSIZE];
       char bssid[WFA_MAC_ADDR_STR_LEN];
       char mac[WFA_MAC_ADDR_STR_LEN];       
#ifdef WFA_P2P
       char devid[WFA_P2P_DEVID_LEN];
		char grpid[WFA_P2P_GRP_ID_LEN];	
	   char p2presult[8];
	   char wpsPin[WFA_WPS_PIN_LEN];
	   caP2pStaGetPskResp_t pskInfo;
	
#endif
	   
       int connected;
   } cmdru;
}dutCmdResponse_t;

#endif
