#!/usr/bin/env bash
if dpkg -s build-essential >/dev/null 2>&1; then
  echo "build-essential is already installed"
else
  echo "build-essential is not installed. Installing it now..."
  sudo apt-get update
  sudo apt-get install -y build-essential
fi

g++ /usr/local/bin/envrep -o /usr/local/bin/envrep-out
rm envrep
mv /usr/local/bin/envrep-out /usr/local/bin/envrep
