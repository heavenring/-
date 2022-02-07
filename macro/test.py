# -*- coding: utf-8 -*-
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.alert import Alert

import datetime
import time


def book(driver, start_time, date, cote) :
    k = datetime.date(int(date[0].strip()), int(date[1].strip()), int(date[2].strip())).weekday() # 일 ~ 토 <- 1 ~ 7
    j = (datetime.date(int(date[0].strip()), int(date[1].strip()), 1).weekday() + int(date[2].strip()) ) // 7 + 1 # 몇번째 주인지 수정?
    c = '0'
    clock = '0'

    # 시간
    for i in range(1,16,2):
        if f"{i + 5}시" == start_time :
            clock = driver.find_element(By.XPATH, f"/html/body/div/div[2]/div/div[7]/form/table/tbody/tr[{j}]/td[{(k + 1) % 7 + 1}]/div/ul/li[{i + 1}]").text
            break
    print(clock,":","예약가능" in clock)
    if "예약가능" in clock:
        driver.find_element(By.XPATH, f'/html/body/div/div[2]/div/div[7]/form/table/tbody/tr[{j}]/td[{(k + 1) % 7 + 1}]/div/ul/li[{i}]').click()  # 시간대 클릭
        time.sleep(0.5)
        
        # 코트선택
        #for i in range(5) :
        c = driver.find_elements(By.XPATH,"/html/body/div/div[2]/div/form/table/tbody/tr[3]/td")
        num = c[0].text.split(' ').strip()
        
        
    else:
        pass



# 년, 월 메모장으로 받을 변수
file = open('monday_am.txt', mode = 'rt', encoding = 'utf-8')

year_text = file.readline().split('=')[1] # xxxx년 받기
year = year_text.strip()
month_text = file.readline().split('=')[1] # x월 받기
month = month_text.strip()
date_text = file.readline().split('=')[1] # 년-월-일 받기
date = date_text.split('-')

cote = '0'

driver = webdriver.Chrome("D:\download\chromedriver.exe")
driver.get('https://reserv.bucheon.go.kr/site/main/main#')
driver.maximize_window() #전체화면으로 열기
driver.implicitly_wait(15)

# 로그인
driver.find_element(By.XPATH, '/html/body/div/div[1]/div[1]/div/div[4]/ul/li[1]/a').click() # 로그인 아이콘
driver.find_element(By.XPATH, '/html/body/div/div[1]/div[2]/ul/li[1]/div/a').click() #회원 로그인 아이콘
driver.implicitly_wait(5)

driver.find_element(By.ID, 'login_id').send_keys('Smn931221') # 아이디 id
driver.find_element(By.ID, 'login_pwd').send_keys('yks931221**') # 비밀번호 pwd
driver.find_element(By.XPATH, '/html/body/div[2]/div[3]/form/div/div/div/div/p[1]/a/img').click() # 로그인 버튼
time.sleep(2)

# 테니스장 서치
driver.get('https://reserv.bucheon.go.kr/site/main/lending/lendingDetail?lending_info_seq=112&inst_cate=01')# 테니스장 예약 페이지로 이동
driver.find_element(By.XPATH, '/html/body/div/div[2]/div/div[4]/a[1]').click() # 예약 일정
driver.implicitly_wait(5)

# 일정 서치
Select(driver.find_element(By.ID,"d1")).select_by_visible_text(year) # 년도선택
Select(driver.find_element(By.ID,"d2")).select_by_visible_text(month) # 월 선택
driver.find_element(By.XPATH, '/html/body/div/div[2]/div/div[7]/div/div/form/button').click() # 검색
driver.implicitly_wait(5)

start_time = file.readline().strip()
print(start_time)
book(driver, start_time, date, cote)



time.sleep(0.5)

driver.find_element(By.XPATH, '/html/body/div/div[1]/div[1]/div/div[4]/ul/li[1]/a').click() #로그아웃