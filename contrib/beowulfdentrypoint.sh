#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start beowulfd traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/beowulfd
  cp /usr/local/bin/beowulf-sv-run.sh /etc/service/beowulfd/run
  chmod +x /etc/service/beowulfd/run
  runsv /etc/service/beowulfd
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/pulltestnetscripts.sh
else
  /usr/local/bin/startpaasbeowulfd.sh
fi
