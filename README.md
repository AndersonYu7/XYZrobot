# XYZRobot
# 軟體安裝

## Arduino 1.0.6 免安裝版
1. 解壓縮 arduino-1.0.6-windows.zip
2. 將hardware中的XYZrobot 複製到 arduino-1.0.6//hardware
3. 將library中的BOLIDE_Player 複製到 arduino-1.0.6//libraries

### 範例程式
1. 將手臂連接電腦
2. 機械手臂6軸+車車：用Arduino 1.0.6開啟 Firmware//RCK100_6DOF_WHEEL//RCK100_6DOF_WHEEL.ino

   機械手臂6軸：用Arduino 1.0.6開啟 Firmware//RCK100_6DOF//RCK100_6DOF.ino
3. 於上方工具列點擊Tools > Board，選擇 XYZrobot(1280)

   ![image](https://github.com/AndersonYu7/XYZrobot/assets/95768254/4854dcc5-672f-4b17-b17d-bb3f5ff4229b)
5. 於工具列點選Tool > Serial Port並選擇手臂相對應的選項(ex:COM8)

   ![image](https://github.com/AndersonYu7/XYZrobot/assets/95768254/476af7f2-1aa4-49d3-a942-f90c02c91cdc)

6. 編譯並上傳程式碼

## 範例程式成果
對應板子上的按鈕有不同的功能

<img src="https://github.com/AndersonYu7/XYZrobot/assets/95768254/8ee50be9-1d7f-48eb-8d1f-914ac83975aa" width="500">

1. 




