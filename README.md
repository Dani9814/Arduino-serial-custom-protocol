# Arduino-serial-custom-protocol

This protocol allows to comunicate to arduino two data: linear velocity and angular velocity. 

The structure is:

 Start	                 Number of package		                 Linear velocity		      Angular velocity		     Checksum
 
	
	255    1                            LSB | MSB          LSB | MSB            LSB

Number of bytes transmited : 7 bytes.

Notes:
LSB:Less significant byte.
MSB: Medium signficant byte.
Checksum: It is the LSB of linear and angular velocity sum. LSB(Linear velocity + Angular velocity) 
