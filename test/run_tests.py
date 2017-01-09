#!/usr/bin/env python3

import json
import os
import re
import subprocess
import sys

def main():
    if not os.path.exists("runner"):
        print("  Test runner not found.")
        return
    if not os.path.exists("config.json"):
        print("  Test config not found.")
        return

    tests = json.load(open("config.json"))

    for current in tests:
        name     = current["name"]
        command  = current["input"]
        expected = current["output"].encode("UTF-8")
        output   = subprocess.check_output(["./runner", command], stderr=subprocess.STDOUT)[:-1]

        if re.fullmatch(expected, output):
            print("{}  Test \"{}\" succeeded.{}".format("\033[1;32m", name, "\033[0m"))
        else:
            print("{}  Test \"{}\" failed.{}".format("\033[1;31m", name, "\033[0m"))

if __name__ == "__main__":
    sys.exit(main())
