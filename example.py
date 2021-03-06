import requests
import recurl


adapter = recurl.CurlEasyAdapter(http_version='1.1', maxconnects=1)
session = requests.Session()

session.mount('https://', adapter)


def print_request(*args, **kwargs):
    response = session.request(*args, **kwargs)

    print('apparent_encoding:', response.apparent_encoding)
    print('content[0:255]:', response.content[0:255])
    print('cookies:', response.cookies)
    print('elapsed:', response.elapsed)
    print('encoding:', response.encoding)
    print('headers:', response.headers)
    print('history:', response.history)
    print('is_permanent_redirect:', response.is_permanent_redirect)
    print('is_redirect:', response.is_redirect)
    print('links:', response.links)
    print('next:', response.next)
    print('ok:', response.ok)
    print('raw:', response.raw)
    print('reason:', response.reason)
    print('request:', response.request)
    print('status_code:', response.status_code)
    print('text[0:255]:', response.text[0:255])
    print('url:', response.url)


print_request('get', 'https://www.google.com/')

