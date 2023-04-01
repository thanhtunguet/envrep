#!/usr/bin/env bash

set -e

if dpkg -s build-essential >/dev/null 2>&1; then
  echo "build-essential is already installed"
else
  echo "build-essential is not installed. Installing it now..."
  sudo apt-get update
  sudo apt-get install -y build-essential
fi

# Biên dịch tệp nguồn C++
g++ -o /usr/local/bin/envrep /usr/local/src/envrep.cpp
rm -rf /usr/local/src/envrep.cpp

# Phân quyền cho tệp thực thi
chmod +x /usr/local/bin/envrep

exit 0
