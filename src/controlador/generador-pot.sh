#!/bin/bash
xgettext --package-name fuentes --package-version 0.1 --default-domain fuentes --output po/fuentes.pot --from-code=utf-8 --copyright-holder="Celina" --msgid-bugs-address="chelinoska@gmail.com" -s -k_ -L C server.c N_client.c
