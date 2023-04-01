envrep
======

Replace environment variable in Configuration files, deploy on Kubernetes and Docker

## Compile

```bash
g++ main.cpp -o envrep
```

## Add to local bin directory

```bash
mv envrep /usr/local/bin/envrep
```

## Run the script

```bash
envrep file1.config file2.config file3.config
```

## Syntax

Variable placeholder: `{VARIABLE_NAME}`

will be replaced with `$VARIABLE_NAME` in current environment
