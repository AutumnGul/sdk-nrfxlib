/*
 * Copyright (c) 2017 - 2022, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef NRF_802154_TX_POWER_H__
#define NRF_802154_TX_POWER_H__

#include <stdint.h>

#include "nrf_802154.h"

/**@brief Convert tx_power value passed through metadata to a raw value in dBm used by the core module.

 * This function also ensures that the value meets the constraints for the current channel.
 *
 * @param[in] channel      The channel to be used for transmission
 * @param[in] tx_power     The value passed to the transmit metadata.
 *
 * @retval                 Returns the power in dBm which will be used to transmit the frame.
 *
 */
nrf_radio_txpower_t nrf_802154_tx_power_convert_metadata_to_raw_value(
    uint8_t                        channel,
    nrf_802154_tx_power_metadata_t tx_power);

/**@brief Get the transmit power stored in PIB after applying the power constraints for the current channel.
 *
 * The current channel is acquired from PIB.
 *
 * @retval                 Returns the constrained power in dBm which will be used to transmit the frame.
 *
 */
nrf_radio_txpower_t nrf_802154_tx_power_constrained_pib_power_get(void);

/**@brief Get the transmit power stored in PIB after applying the power constraints for the given channel.
 *
 * @param[in] channel      The channel based on which the power should be constrained
 *
 * @retval                 Returns the power in dBm which will be used to transmit the frame.
 *
 */
nrf_radio_txpower_t nrf_802154_tx_power_constrained_pib_power_for_channel_get(uint8_t channel);

/**
 *@}
 **/

#endif // NRF_802154_TX_POWER_H__
