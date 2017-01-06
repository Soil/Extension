#!/usr/bin/env python3

import os
import sys
import subprocess

def main():
    if not os.path.exists("./test"):
        print("  Test utility not found.")
        return

    tests = {
        "version": "0.1"
    }

    for command in tests:
        output   = subprocess.check_output(["./test", command], stderr=subprocess.STDOUT)[:-1]
        expected = tests[command].encode("UTF-8")
        if output == expected:
            print("  Test for {} succeeded.".format(command))
        else:
            print("{}  Test for {} failed.{}".format("\033[1;31m", command, "\033[0m"))

if __name__ == "__main__":
    sys.exit(main())
