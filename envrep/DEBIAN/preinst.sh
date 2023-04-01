#!/usr/bin/env bash

set -e

if dpkg -s build-essential >/dev/null 2>&1; then
  echo "build-essential is already installed"
else
  echo "build-essential is not installed. Installing it now..."
  apt-get update
  apt-get install -y build-essential
fi

# Biên dịch tệp nguồn C++
echo "Compiling envrep.cpp -> /usr/local/bin/envrep"
g++ -o /usr/local/bin/envrep /usr/local/src/envrep.cpp

# Phân quyền cho tệp thực thi
echo "Allow executing /usr/local/bin/envrep"
chmod +x /usr/local/bin/envrep

exit 0
