#ifndef __OMEGA_ESPNOW_CONTROLLER_H__
#define __OMEGA_ESPNOW_CONTROLLER_H__

#include <string.h>

#include <esp_err.h>
#include <esp_event.h>
#include <esp_log.h>
#include <esp_netif.h>
#include <esp_now.h>
#include <esp_wifi.h>
#include <nvs_flash.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        uint8_t _peer_index;
        esp_now_peer_info_t _peer_devices[20];
        void (*_receive_callback)(const uint8_t *, uint8_t *, int);
        void (*_transmit_callback)(const uint8_t *, esp_now_send_status_t);
    } OmegaESPNOWController_t;

    void OmegaESPNOWController_reset_module(OmegaESPNOWController_t *);
    void OmegaESPNOWController_initialize_with_defaults(OmegaESPNOWController_t *);
    void OmegaESPNOWController_set_receive_callback(OmegaESPNOWController_t *, void (*)(const uint8_t *, uint8_t *, size_t));
    void OmegaESPNOWController_set_transmit_callback(OmegaESPNOWController_t *, void (*)(const uint8_t *, esp_now_send_status_t));
    void OmegaESPNOWController_add_peer(OmegaESPNOWController_t *, const uint8_t *);
    void OmegaESPNOWController_send_packet(OmegaESPNOWController_t *, const uint8_t *, uint8_t *, size_t);

    void _receive_callback(const uint8_t *, uint8_t *, size_t);
    void _transmit_callback(const uint8_t *, esp_now_send_status_t);

#ifdef __cplusplus
}
#endif

#endif