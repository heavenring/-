from setting import data,date
import datetime

def makeNextMonth():
    now=datetime.datetime.now()
    y=now.year
    m=now.month
    y+=m//12
    m=(m%12)+1
    return (y,m)


def readBookInfoes():
    '''정보를 읽어와서 가공 후 반환'''
    infos=[]
    f=open("bookInfo.txt","r",encoding = 'utf-8')
    ym=f.readline().strip()

    if(ym=="."):
        ym=makeNextMonth()
    else:
        ym = ym.split('-')
    date.setYear(ym[0])
    date.setMonth(ym[1])

    while (True):
        tmp=[None,None,None]#요일,계정,시간,코트
        line = f.readline()#계정
        if not line:
            break
        else:
            tmp[0]=line.strip().split(',')[0:2]#계정
            tmp[1]=int(f.readline().strip())#시간
            tmp[2] =int(f.readline().strip())#코트
            line=f.readline().strip()#요일
            for w in line:
                wnum=data.weekdayToweight(w)
                infos.append([wnum]+tmp)

    infos.sort()
    f.close()
    return infos

def waiting(endtime):
    '''endtime까지 대기'''
    while(datetime.datetime.now()<endtime):
        pass

def getFirstWeekday(weekday):
    '''특정 요일의 이번째 첫번째 날이 몇일인지 반환'''
    one=datetime.datetime(date.getYear(),date.getMonth(),1).weekday()
    diff=(data.getWeekdayNum(weekday)-one+7)%7
    return diff+1