#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime

for i in range(10000):
    sleep(random.random())
    fmt = "{ip} - [{date}] \"GET /projects/260 HTTP/1.1\" {status} {size}\n"
    sys.stdout.write(fmt.format(
        ip='.'.join(str(random.randint(1, 255)) for _ in '0.0.0.0'.split('.')),
        date=datetime.datetime.now(),
        status=random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
        size=random.randint(1, 1024)
    ))
    sys.stdout.flush()
