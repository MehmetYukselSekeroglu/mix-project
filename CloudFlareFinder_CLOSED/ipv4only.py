import sys


try:
    file = sys.argv[1]
    raw_dns = open(f"{file}","r")
    out_file = open(f"dns_list.txt","w")
    for line in raw_dns:
        if len(line) < 16 and ":" not in line:
            out_file.write(line)
    raw_dns.close()
    out_file.close()
except Exception:
    print("No file detected!")