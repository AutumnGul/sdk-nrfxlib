# nrf_cc3xx_platform is not a driver in the old APIs. Once ctr_drbg/hmac_drbg 
# gets real driver API support then the placement here makes more sense
if(TARGET platform_cc3xx)
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/nrf_cc3xx_platform)
endif()

if(CONFIG_PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT OR CONFIG_MBEDTLS_LEGACY_CRYPTO_C)

  if(CONFIG_PSA_CRYPTO_DRIVER_BUILTIN)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/builtin)
  endif()

  if(CONFIG_PSA_CRYPTO_DRIVER_CC3XX AND NOT CONFIG_BUILD_WITH_TFM)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/nrf_cc3xx)
  endif()

  if(CONFIG_PSA_CRYPTO_DRIVER_OBERON OR CONFIG_OBERON_BACKEND)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/nrf_oberon)
  endif()

endif()
