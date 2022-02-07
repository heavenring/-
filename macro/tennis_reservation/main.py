from tennis_reservation import book
from multiprocessing import Process
from util import *
import calendar
from setting import Driver
import time

if __name__=='__main__':

    infos=readBookInfoes()#요일,계정,시간,코트
    drivers=Driver()
    print(infos)

    startday=0
    now=datetime.datetime.now()
    if(now.year==date.getYear() and now.month==date.getMonth()): # 이전날짜 예약 안하는 코드
        startday=now.day+1

    
    for info in infos: # 받은 정보 1계정씩 사용
        day=getFirstWeekday(data.weightToweekday(info[0])) #가중치 함수 호출 및 그 달의 첫째날 요일 얻기
        last=calendar.monthrange(date.getYear(),date.getMonth())[1] # 그 달의 마지막날

        start_time = datetime.datetime(now.year, now.month, day = 14, hour = 23, minute = 59, second = 0)
        print(start_time)
        waiting(start_time) # 예약시작 2분전에 로그인 시작

        driver=drivers.getDriver(info[1][0],info[1][1]) # 로그인한 새창 사용

        start_time = datetime.datetime(now.year, now.month, day = 15, hour = 0, minute = 0, second = 1)
        waiting(start_time) # 예약프로그램 돌아가기 시작하는 시간

        while(day<=last):
            if(day>=startday):
                book(driver,[date.getYear(),date.getMonth(),day],info[2],info[3])
            day += 7

        print(driver)
