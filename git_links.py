from urllib import urlopen

response = urlopen('http://www.github.com')
line = response.readline()
while(line != ""):
    link = line.find('<link')
    if link != -1:
        print(line[link:])
    line = response.readline()
