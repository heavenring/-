import time
from setting import FileManager
def totalErrorProcess(id, reson):
    print(id,'fail')
    current_time = time.strftime("%Y.%m.%d/%H:%M:%S", time.localtime(time.time()))
    file=FileManager.getfile("Log/Log.txt")
    file.write(f"[{current_time}] - {reson}\n")

def bookresult(id,str):
    print(id,str)