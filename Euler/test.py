import sys
from urllib.parse import urlparse,parse_qs

parsed = urlparse(sys.argv[1])
parsedqs = parse_qs(parsed.query)
parsedqs = {k: v[0] for k, v in parsedqs.items()}
sys.stdout.write(str(parsedqs))