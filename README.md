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
envrep filename.config
```

## Syntax

Variable placeholder: `{VARIABLE_NAME}`

will be replaced with `$VARIABLE_NAME` in current environment
