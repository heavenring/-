# -*- coding: utf-8 -*-
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.alert import Alert
from log import *

import datetime
import time


def book(driver, date, start_time, cote):
    try :
        k = datetime.date(date[0], date[1], date[2]).weekday() # 일 ~ 토 <- 1 ~ 7
        j = (datetime.date(date[0], date[1], 1).weekday() + date[2]) // 7 + 1 # 몇번째 주인지 수정?
        clock = '0'

        # 테니스장 서치
        driver.get('https://reserv.bucheon.go.kr/site/main/lending/lendingDetail?lending_info_seq=112&inst_cate=01')  # 테니스장 예약 페이지로 이동
        driver.find_element(By.XPATH, '/html/body/div/div[2]/div/div[4]/a[1]').click()  # 예약 일정
        driver.implicitly_wait(5)

        # 일정 서치
        Select(driver.find_element(By.ID, "d1")).select_by_visible_text(f'{date[0]}년')  # 년도선택
        Select(driver.find_element(By.ID, "d2")).select_by_visible_text(f'{date[1]}월')  # 월 선택
        driver.find_element(By.XPATH, '/html/body/div/div[2]/div/div[7]/div/div/form/button').click()  # 검색
        driver.implicitly_wait(5)
        
        # 시간
        for i in range(1,16,2):
            if i + 5 == start_time :
                clock = driver.find_element(By.XPATH, f"/html/body/div/div[2]/div/div[7]/form/table/tbody/tr[{j}]/td[{(k + 1) % 7 + 1}]/div/ul/li[{i + 1}]").text
                break
        print(clock,":","예약가능" in clock)
        if "예약가능" in clock:
            driver.find_element(By.XPATH, f'/html/body/div/div[2]/div/div[7]/form/table/tbody/tr[{j}]/td[{(k + 1) % 7 + 1}]/div/ul/li[{i}]').click()  # 시간대 클릭
            time.sleep(0.5)
            
            # 코트선택
            c = driver.find_elements(By.XPATH,"/html/body/div/div[2]/div/form/table/tbody/tr[3]/td")
            num = c[0].text.split(' ')

            for j in range(len(num)):
                print(f"{num[j]} 확인")
                if num[j] in f'{cote}코트' :
                    print(f"{cote}코트 선택 진입")
                    driver.find_element(By.XPATH, f'/html/body/div/div[2]/div/form/table/tbody/tr[3]/td/input[{j + 1}]').click() # 코트선택
                    driver.find_element(By.XPATH, '/html/body/div/div[2]/div/form/table/tbody/tr[12]/td/div/input[1]').click()  # 동의1
                    driver.find_element(By.XPATH, '/html/body/div/div[2]/div/form/table/tbody/tr[13]/td/div/input[1]').click()  # 동의2
                    driver.find_element(By.XPATH, '/html/body/div/div[2]/div/form/div/a[1]').click()  # 신청하기
                    Alert(driver).accept()
                    break
                else :
                    print(f"{num[j]}아님")
                    pass
    
    except Exception as e:
        totalErrorProcess(e,"예약실패")
    else:
        bookresult(date,"프로그램 성공")





