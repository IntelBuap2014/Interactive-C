#!/bin/bash
xgettext --package-name server --package-version 0.1 --default-domain server --output po/server.pot --from-code=utf-8 --copyright-holder="Celina" --msgid-bugs-address="chelinoska@gmail.com" -s -k_ -L C server.c
