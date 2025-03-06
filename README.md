# proxy_exec
Execute any command by proxy. Set environment variable `PROXY_EXEC_CMD` to a command you need to run when `proxy_exec` is called. All command line parameters will be passed to that command as is.
Exit code is proxied too except when `PROXY_EXEC_CMD` not set. Then `1` is returned.
