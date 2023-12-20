# XYZRobot
# 軟體安裝

## Arduino 1.0.6 免安裝版與環境安裝
1. 解壓縮 arduino-1.0.6-windows.zip
2. 將hardware中的XYZrobot 複製到 arduino-1.0.6//hardware
3. 將library中的BOLIDE_Player 複製到 arduino-1.0.6//libraries

### 範例程式
1. 將手臂連接電腦
2. 機械手臂6軸+車車：用Arduino 1.0.6開啟 Firmware//RCK100_6DOF_WHEEL//RCK100_6DOF_WHEEL.ino

   機械手臂6軸：用Arduino 1.0.6開啟 Firmware//RCK100_6DOF//RCK100_6DOF.ino
3. 於上方工具列點擊Tools > Board，選擇 XYZrobot(1280)

   ![image](pic/291841840-4854dcc5-672f-4b17-b17d-bb3f5ff4229b.png)
5. 於工具列點選Tool > Serial Port並選擇手臂相對應的選項(ex:COM8)

   ![image](pic/291842393-476af7f2-1aa4-49d3-a942-f90c02c91cdc.png)

6. 編譯並上傳程式碼

## 範例程式成果
對應板子上的按鈕有不同的功能

<img src="pic/button.jpg" width="500">

1. 功能一

<img src="pic/1.gif" width="500">

2. 功能二

<img src="pic/2.gif" width="500">

3. 功能三

<img src="pic/3.gif" width="500">

4. 功能四

<img src="pic/4.gif" width="500">

## 動作編輯器安裝
1. 解壓縮 動作編輯器V3_離線版_V3.19.0520.1.zip
2. 點擊執行setup.exe
3. 點擊Install安裝動作編輯器

![image](pic/install.png)

## 動作編輯器前置設定
1. 點擊新專案

<img src="pic/new_project.jpg" width="720">

3. 選擇機種與創建名稱

![image](pic/chose_name_and_machine.png)

4. 偏好設定->序列埠設定(選擇自己電腦顯示的序列埠)

![image](pic/USB_COM.png)

5. 設定完成即可動作編輯

## 動作編輯器範例
### 透過動作編輯與連續動作編輯抓取物品(test_arm.xyz)

* 動作編輯畫面

<img src="pic/move.jpg" width="720">

* 連續動作編輯畫面

<img src="pic/continue_move.png" width="720">

* 實際運作範例













