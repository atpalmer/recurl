# Recurl: Curl adapter for requests

```
import requests
import requests_curl


adapter = requests_curl.CurlEasyAdapter()
session = requests.Session()
session.mount('https://', adapter)

response = session.get('https://www.google.com/')

print(response.ok)
```

...or...

```
import requests_curl


session = requests_curl.Session()
response = session.get('https://www.google.com/')
print(response.ok)
```

...or...

```
import requests_curl


response = requests_curl.get('https://www.google.com/')
print(response.ok)
```
