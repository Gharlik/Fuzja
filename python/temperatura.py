import smbus
import time

# Get I2C bus
bus = smbus.SMBus(1)

# MCP9808 address, 0x18(24)
# Select configuration register, 0x01(1)
#		0x0000(00)	Continuous conversion mode, Power-up default
config = [0x00, 0x00]
bus.write_i2c_block_data(0x18, 0x01, config)
# MCP9808 address, 0x18(24)
# Select resolution rgister, 0x08(8)
#		0x03(03)	Resolution = +0.0625 / C
bus.write_byte_data(0x18, 0x08, 0x03)

time.sleep(0.5)



# Convert the data to 13-bits
while True:
    data = bus.read_i2c_block_data(0x18, 0x05, 2)
    ctemp = ((data[0] & 0x1F) * 256) + data[1]
    if ctemp > 4095 :
        ctemp -= 8192
    ctemp = ctemp * 0.0625

    # Output data to screen
    print ("Temperature in Celsius is    : %.2f C" %ctemp)
    time.sleep(2)
