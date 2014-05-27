; BIOS RAM usage (begins at $10F300)

BIOS_WORKRAM			equ $10F300

;SSP_END:					; supervisor stack
;	ds.b $900
;	ds.b $180

;$10FD00 ; stack?

;$10FD4C ; (word) debug bios: call code for some shit?
; $00		Bus Error/Monitor Startup
; $04		Adddress Error
; $08		Illegal Instruction
; $0C		Divide by 0
; $10		CHK
; $14		TRAPV
; $18		Privilege Violation
; $1C		Trace

; $10FD74 ??
; $10FD76 ??
; $10FD78 ??

;===================================;
BIOS_WORK0				equ $10FD80	; beginning of actual BIOS work RAM

BIOS_SYSTEM_MODE		equ $10FD80	; (byte) VBL for $00=system,$80=game
BIOS_SYSRET_STATUS		equ $10FD81	; (byte) Stores function code for SYSTEM_RETURN
BIOS_MVS_FLAG			equ $10FD82	; (byte) 0=AES,1=MVS
BIOS_COUNTRY_CODE		equ $10FD83	; (byte) 0=Japan,1=USA,2=Europe (xxx:Korea?)
BIOS_GAME_DIP			equ $10FD84	; $10FD84-$10FD93
;-----------------------------------;
; INPUT_1
BIOS_P1STATUS			equ $10FD94	; (byte) Controller 1 status
BIOS_P1PREVIOUS			equ $10FD95	; (byte) Inputs from last frame
BIOS_P1CURRENT			equ $10FD96	; (byte) Inputs from current frame
BIOS_P1CHANGE			equ $10FD97	; (byte) Active-edge input
BIOS_P1REPEAT			equ $10FD98	; (byte) Auto-repeat flag
BIOS_P1TIMER			equ $10FD99	; (byte) Input repeat timer
;-----------------------------------;
; INPUT_2
BIOS_P2STATUS			equ $10FD9A	; (byte) Controller 2 status
BIOS_P2PREVIOUS			equ $10FD9B	; (byte) Inputs from last frame
BIOS_P2CURRENT			equ $10FD9C	; (byte) Inputs from current frame
BIOS_P2CHANGE			equ $10FD9D	; (byte) Active-edge input
BIOS_P2REPEAT			equ $10FD9E	; (byte) Auto-repeat flag
BIOS_P2TIMER			equ $10FD9F	; (byte) Input repeat timer
;-----------------------------------;
; INPUT_3
BIOS_P3STATUS			equ $10FDA0	; (byte) Controller 3 status
BIOS_P3PREVIOUS			equ $10FDA1	; (byte) Inputs from last frame
BIOS_P3CURRENT			equ $10FDA2	; (byte) Inputs from current frame
BIOS_P3CHANGE			equ $10FDA3	; (byte) Active-edge input
BIOS_P3REPEAT			equ $10FDA4	; (byte) Auto-repeat flag
BIOS_P3TIMER			equ $10FDA5	; (byte) Input repeat timer
;-----------------------------------;
; INPUT_4
BIOS_P4STATUS			equ $10FDA6	; (byte) Controller 4 status
BIOS_P4PREVIOUS			equ $10FDA7	; (byte) Inputs from last frame
BIOS_P4CURRENT			equ $10FDA8	; (byte) Inputs from current frame
BIOS_P4CHANGE			equ $10FDA9	; (byte) Active-edge input
BIOS_P4REPEAT			equ $10FDAA	; (byte) Auto-repeat flag
BIOS_P4TIMER			equ $10FDAB	; (byte) Input repeat timer
;-----------------------------------;
; INPUT_S
BIOS_STATCURNT			equ $10FDAC	; (byte)
BIOS_STATCHANGE			equ $10FDAD	; (byte)
;-----------------------------------;
BIOS_USER_REQUEST		equ $10FDAE	; (byte) Command for USER ($122)
BIOS_USER_MODE			equ $10FDAF	; (byte) Current game status
;-----------------------------------;
BIOS_CREDIT1_DEC		equ $10FDB0	; (byte) Credit decrement Player 1 (BCD)
BIOS_CREDIT2_DEC		equ $10FDB1	; (byte) Credit decrement Player 2 (BCD)
BIOS_CREDIT3_DEC		equ $10FDB2	; (byte) Credit decrement Player 3 (BCD)
BIOS_CREDIT4_DEC		equ $10FDB3	; (byte) Credit decrement Player 4 (BCD)
;-----------------------------------;
BIOS_START_FLAG			equ $10FDB4	; (byte)
BIOS_PLAYER1_MODE		equ $10FDB6	; (byte)
BIOS_PLAYER2_MODE		equ $10FDB7	; (byte)
BIOS_PLAYER3_MODE		equ $10FDB8	; (byte)
BIOS_PLAYER4_MODE		equ $10FDB9	; (byte)
;-----------------------------------;
BIOS_MESS_POINT			equ $10FDBE	; (dword) pointer to buffer
BIOS_MESS_BUSY			equ $10FDC2	; (word) 0=run MESS_OUT, 1=skip MESS_OUT
;-----------------------------------;
BIOS_CARD_COMMAND		equ $10FDC4
BIOS_CARD_MODE			equ $10FDC5
BIOS_CARD_ANSWER		equ $10FDC6
BIOS_CARD_START			equ $10FDC8
BIOS_CARD_SIZE			equ $10FDCC
BIOS_CARD_FCB			equ $10FDCE
BIOS_CARD_SUB			equ $10FDD0
;-----------------------------------;
; DATE_TIME
BIOS_YEAR				equ $10FDD2
BIOS_MONTH				equ $10FDD3
BIOS_DAY				equ $10FDD4
BIOS_WEEKDAY			equ $10FDD5
BIOS_HOUR				equ $10FDD6
BIOS_MINUTE				equ $10FDD7
BIOS_SECOND				equ $10FDD8
;-----------------------------------;
BIOS_SELECT_TIMER		equ $10FDDA	; (byte) "BIOS_COMPULSION_TIMER"
;BIOS_START_TEST			equ $10FDDC	; ()
;BIOS_COIN_LEVER			equ $10FDDE	; ()

; AOF's $10FDDA-area defs:
;SELECT_TIMER	ds.w 1
;START_TEST		ds.w 1
;COIN_LEVER		ds.w 1

;===================================;
BIOS_WORK1				equ $10FE00

BIOS_CREDIT1			equ $10FE00	; (byte)
BIOS_CREDIT2			equ $10FE01	; (byte)
BIOS_CREDIT3			equ $10FE02	; (byte)
BIOS_CREDIT4			equ $10FE03	; (byte)
;-----------------------------------;
BIOS_SWITCH_STORE		equ $10FE04	; (dword)
;-----------------------------------;
BIOS_UNDER_CREDIT1		equ $10FE08	; (byte)
BIOS_UNDER_CREDIT2		equ $10FE09	; (byte)
BIOS_UNDER_CREDIT3		equ $10FE0A	; (byte)
BIOS_UNDER_CREDIT4		equ $10FE0B	; (byte)
BIOS_UNDER_CREDIT5		equ $10FE0C	; (byte)
BIOS_UNDER_CREDIT6		equ $10FE0D	; (byte)
BIOS_UNDER_CREDIT7		equ $10FE0E	; (byte)
BIOS_UNDER_CREDIT8		equ $10FE0F	; (byte)
;-----------------------------------;
BIOS_COIN1_NOR_CRED		equ $10FE10	; (word)
BIOS_COIN2_NOR_CRED		equ $10FE12	; (word)
BIOS_COIN1_CONT_CRED	equ $10FE14	; (word)
BIOS_COIN2_CONT_CRED	equ $10FE16	; (word)
;-----------------------------------;
BIOS_SELECT_FREE		equ $10FE18	; (byte)
BIOS_NON_LIMIT			equ $10FE1A	; (word)
BIOS_DEMO_SOUND			equ $10FE1C ; (byte)
BIOS_INIT_MARK			equ $10FE1E	; (word)
BIOS_SR_STORE			equ $10FE20	; (word)
BIOS_VERSION_BASE		equ $10FE22	; (dword)
BIOS_GD_STORE			equ $10FE26	; (byte) 32 bytes

;===================================;
BIOS_WORK2				equ $10FE80

BIOS_DEVMODE			equ $10FE80	; (byte)
;$10FE81-$10FE87 "Power on ID code"??
BIOS_FRAMECOUNT			equ $10FE88	; (dword) "SYS_INT1_TIMER"
BIOS_SYS_STOPPER		equ $10FE8C	; (byte) "system stopper", actually BIOS VBlank flag
BIOS_Z80_BANK			equ $10FE8D	; (byte)
BIOS_SYSTEM_MODE2		equ $10FE8E	; (word)
;-----------------------------------;
BIOS_CARD_TIMER			equ $10FE90	; (word)
BIOS_CARD_START2		equ $10FE92	; (dword)
BIOS_CARD_SIZE2			equ $10FE96	; (word)
BIOS_CARD_FCB2			equ $10FE98	; (word)
BIOS_CARD_SUB2			equ $10FE9A	; (word)
BIOS_DIR_BUFFER			equ $10FE9C	; (byte) 20 bytes
BIOS_DIR_NUMBER			equ $10FEB0	; (word) 5 words
;-----------------------------------;
BIOS_FIX_STORE_FLAG		equ $10FEBA	; (byte)
BIOS_LED_OFF			equ $10FEBB	; (byte)
BIOS_IN_TEST			equ $10FEBC	; (byte)
BIOS_INST_MODE			equ $10FEBD	; (byte)
BIOS_START_BUSY			equ $10FEBE	; (byte)
BIOS_BACKUP_MODE		equ $10FEBF	; (byte)
BIOS_INST_RAD			equ $10FEC0	; (dword)
BIOS_INST_RCO			equ $10FEC4	; (byte)
BIOS_TITLE_MODE			equ $10FEC5	; (byte)
BIOS_MESS_STACK			equ $10FEC6	; (dword) 5 dwords
;-----------------------------------;
BIOS_STATCURNT_RAW		equ $10FEDC	; (byte) "INPUT_SS"
BIOS_STATCHANGE_RAW		equ $10FEDD	; (byte)
BIOS_INPUT_TT1			equ $10FEDE	; (byte)
BIOS_INPUT_TT2			equ $10FEDF	; (byte)

BIOS_KYOUSEI_MODE		equ $10FEE0	; (byte) "KYOUSEI_MODE"
BIOS_SYS_STOP			equ $10FEE1	; (byte) "SYS_STOP"
BIOS_CS_REMAIN			equ $10FEE2	; (byte) "CS_REMAIN"
BIOS_INT_OFF			equ $10FEE3	; (byte) "INT_OFF"
BIOS_INT1_TIMER2		equ $10FEE4	; (word) "INT1_TIMER2"
;-----------------------------------;
;INPUT_5
BIOS_P5STATUS			equ $10FEE8	; (byte)
BIOS_P5PREVIOUS			equ $10FEE9	; (byte)
BIOS_P5CURRENT			equ $10FEEA	; (byte)
BIOS_P5CHANGE			equ $10FEEB	; (byte)
BIOS_P5REPEAT			equ $10FEEC	; (byte)
BIOS_P5TIMER			equ $10FEED	; (byte)
;-----------------------------------;
;INPUT_6
BIOS_P6STATUS			equ $10FEEE	; (byte)
BIOS_P6PREVIOUS			equ $10FEEF	; (byte)
BIOS_P6CURRENT			equ $10FEF0	; (byte)
BIOS_P6CHANGE			equ $10FEF1	; (byte)
BIOS_P6REPEAT			equ $10FEF2	; (byte)
BIOS_P6TIMER			equ $10FEF3	; (byte)
;-----------------------------------;
BIOS_MESS_BUFFER		equ $10FF00	; 100 byte buffer