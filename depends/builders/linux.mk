// Copyright (c) 2017 The PuffsCoin developers
build_linux_SHA256SUM = sha256sum
build_linux_DOWNLOAD = curl --location --fail --connect-timeout $(DOWNLOAD_CONNECT_TIMEOUT) --retry $(DOWNLOAD_RETRIES) -o
