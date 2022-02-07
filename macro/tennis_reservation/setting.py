from selenium import webdriver
from selenium.webdriver.common.by import By
import  time

class FileManager():
    filelist={}

    def getfile(self,file):
        if(not(file in self.filelist)):
            self.filelist[file]=open(file, "a")
        return self.filelist[file]

    def __del__(self):
        for f in self.filelist.values():
            f.close()


class Driver():
    __drivers={}

    def __login(self, id,password):
        try:
            driver = webdriver.Chrome("chromedriver.exe")
            driver.get('https://reserv.bucheon.go.kr/site/main/main#')
            driver.maximize_window()  # 전체화면으로 열기
            driver.implicitly_wait(15)

            # 로그인
            driver.find_element(By.XPATH, '/html/body/div/div[1]/div[1]/div/div[4]/ul/li[1]/a').click()  # 로그인 아이콘
            driver.find_element(By.XPATH, '/html/body/div/div[1]/div[2]/ul/li[1]/div/a').click()  # 회원 로그인 아이콘
            driver.implicitly_wait(5)

            driver.find_element(By.ID, 'login_id').send_keys(id)  # 아이디 id
            time.sleep(0.2)
            driver.find_element(By.ID, 'login_pwd').send_keys(password)  # 비밀번호 pwd
            driver.find_element(By.XPATH, '/html/body/div[2]/div[3]/form/div/div/div/div/p[1]/a/img').click()  # 로그인 버튼
            time.sleep(2)
            return driver
        except Exception as e:
            print(e)
            return None

    def getDriver(self, id, password):
        if(not (id in self.__drivers)):
            #드라이버가 없을 경우
            self.__drivers[id]=self.__login(id,password)
        return self.__drivers[id]


class Data():
    '''여러 곳에서 공유될 데이터들'''
    MAIN_PAGE = 'https://reserv.bucheon.go.kr/site/main/main#'
    TENNIS_PAGE = 'https://reserv.bucheon.go.kr/site/main/lending/lendingList?lending_inst_nm=tennis&inst_cate=01'

    __WEEKDAY_TO_WEIGHT={'토':0,'일':1,'월':2,'화':3,'수':4,'목':5,'금':6} # 요일 예약순서
    __WEIGHT_TO_WEEKDAY=[]
    __WEEKDAY_NUM={'월':0,'화':1,'수':2,'목':3,'금':4,'토':5,'일':6,}

    def __init__(self):
        Data.__WEIGHT_TO_WEEKDAY=[i for i in range(7)]
        for k,v in Data.__WEEKDAY_TO_WEIGHT.items():
            Data.__WEIGHT_TO_WEEKDAY[v]=k


    def weekdayToweight(self, weekday):
        return Data.__WEEKDAY_TO_WEIGHT[weekday]

    def weightToweekday(self,num): # 가중치에 따른 정렬
        return Data.__WEIGHT_TO_WEEKDAY[num]

    def getWeekdayNum(self,weekday):
        return Data.__WEEKDAY_NUM[weekday]


class Date():
    '''이 프로그램에서 사용할 년 월'''
    __year = 0
    __month = 0
    def setYear(self,year): # 년 구하는거
        Data.__year=int(year)

    def setMonth(self,month): # 월 구하는거
        Data.__month=int(month)

    def getYear(self): 
        return Data.__year

    def getMonth(self): 
        return Data.__month

options=webdriver.ChromeOptions()
options.add_argument('start-maximized')

data=Data()
date=Date()

if __name__=='__main__':
    print(Data.TENNIS_PAGE)
    print(Data.getYear())
    print(Data.getMonth())
    Data.setYear(1)