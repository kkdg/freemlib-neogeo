; Neo-Geo freemlib Sound Driver RAM
;==============================================================================;
; Usable RAM exists from 0xF800 to 0xFFFF.
RAM:
	org $F800
;==============================================================================;
; Sound Driver Section
;==============================================================================;
dummyByte			ds 1		; dummy byte used for RAM clearing, etc.
;------------------------------------------------------------------------------;
; Commands
curCommand			ds 1		; Current command to handle
prevCommand			ds 1		; Previous command handled
commandBuffer		ds 96		; 96 byte command buffer (todo: is this enough?)

dataMode			ds 1		; (0=normal, 1=send to 68k, 2=receive from 68k)

;------------------------------------------------------------------------------;
; Channel Playback
musicToggle			ds 1		; Master Toggle for Music
soundToggle			ds 1		; Master Toggle for Sound Effects

chanToggle			ds 1		; Overall toggle for SSG, FM, and PCM (1 bit each)
ssgToggle			ds 1		; Specific SSG channel toggles ($07 p4/5)
fmToggle			ds 1		; Specific FM channel toggles
pcmToggle			ds 1		; Specific ADPCM channel toggles

;------------------------------------------------------------------------------;
; Song Attributes/Playback
curSong				ds 1		; Current Song number
curTempo			ds 2		; Current Song Tempo (0-511, for now...)

songLoops			ds 1		; Does the song loop?
loopPoint			ds 2		; Pointer to loop point (shared between channels for now)

; FM Channel 1
; FM Channel 2
; FM Channel 3
; FM Channel 4
; SSG Channel A
; SSG Channel B
; SSG Channel C

;==============================================================================;
; YM2610 Section
;==============================================================================;
; System variables
; Status 0 (Timer flags and Busy)
; Status 1 (ADPCM A and B status)

;==============================================================================;
; Timer variables
intTimerControl		ds 1		; ($27) Timer Control and Mode
intTimerA_Lo		ds 1		; ($24) Timer A value LSB
intTimerA_Hi		ds 1		; ($25) Timer A value MSB
intTimerB			ds 1		; ($26) Timer B value

;==============================================================================;
; SSG variables (Ports 4/5)
intSSG_Enable		ds 1		; ($07) SSG channel enable
intSSG_EnvPeriodL	ds 1		; ($0B) Envelope Period Fine Tune
intSSG_EnvPeriodH	ds 1		; ($0C) Envelope Period Coarse Tune
intSSG_EnvShape		ds 1		; ($0D) Envelope Shape Cycle

;------------------------------------------------------------------------------;
; * SSG Pulse Channels (A,B,C)
intSSG_A_PeriodL	ds 1		; ($00) Tone Period Fine Tune
intSSG_A_PeriodH	ds 1		; ($01) Tone Period Coarse Tune
intSSG_A_Volume		ds 1		; ($08) Volume and Mode

intSSG_B_PeriodL	ds 1		; ($02) Tone Period Fine Tune
intSSG_B_PeriodH	ds 1		; ($03) Tone Period Coarse Tune
intSSG_B_Volume		ds 1		; ($09) Volume and Mode

intSSG_C_PeriodL	ds 1		; ($04) Tone Period Fine Tune
intSSG_C_PeriodH	ds 1		; ($05) Tone Period Coarse Tune
intSSG_C_Volume		ds 1		; ($0A) Volume and Mode

;------------------------------------------------------------------------------;
; * SSG Noise Channel
intSSG_Noise		ds 1		; ($06) Noise Period

;==============================================================================;
; ADPCM-A variables (Ports 6/7)
intPCMA_Dump		ds 1		; ($00) Dump (Key On/Off) and Channel toggle
intPCMA_MasterVol	ds 1		; ($01) Master Volume

;------------------------------------------------------------------------------;
; * ADPCM-A channels (1-6)
intPCMA1_Volume		ds 1		; ($08)
intPCMA1_StartL		ds 1		; ($10) Sample Start Address/256 (LSB)
intPCMA1_StartH		ds 1		; ($18) Sample Start Address/256 (MSB)
intPCMA1_EndL		ds 1		; ($20) Sample End Address/256 (xSB)
intPCMA1_EndH		ds 1		; ($28) Sample End Address/256 (xSB)

intPCMA2_Volume		ds 1		; ($09)
intPCMA2_StartL		ds 1		; ($11) Sample Start Address/256 (LSB)
intPCMA2_StartH		ds 1		; ($19) Sample Start Address/256 (MSB)
intPCMA2_EndL		ds 1		; ($21) Sample End Address/256 (LSB)
intPCMA2_EndH		ds 1		; ($29) Sample End Address/256 (MSB)

intPCMA3_Volume		ds 1		; ($0A)
intPCMA3_StartL		ds 1		; ($12) Sample Start Address/256 (LSB)
intPCMA3_StartH		ds 1		; ($1A) Sample Start Address/256 (MSB)
intPCMA3_EndL		ds 1		; ($22) Sample End Address/256 (LSB)
intPCMA3_EndH		ds 1		; ($2A) Sample End Address/256 (MSB)

intPCMA4_Volume		ds 1		; ($0B)
intPCMA4_StartL		ds 1		; ($13) Sample Start Address/256 (LSB)
intPCMA4_StartH		ds 1		; ($1B) Sample Start Address/256 (MSB)
intPCMA4_EndL		ds 1		; ($23) Sample End Address/256 (LSB)
intPCMA4_EndH		ds 1		; ($2B) Sample End Address/256 (MSB)

intPCMA5_Volume		ds 1		; ($0C)
intPCMA5_StartL		ds 1		; ($14) Sample Start Address/256 (LSB)
intPCMA5_StartH		ds 1		; ($1C) Sample Start Address/256 (MSB)
intPCMA5_EndL		ds 1		; ($24) Sample End Address/256 (LSB)
intPCMA5_EndH		ds 1		; ($2C) Sample End Address/256 (MSB)

intPCMA6_Volume		ds 1		; ($0D)
intPCMA6_StartL		ds 1		; ($15) Sample Start Address/256 (LSB)
intPCMA6_StartH		ds 1		; ($1D) Sample Start Address/256 (MSB)
intPCMA6_EndL		ds 1		; ($25) Sample End Address/256 (LSB)
intPCMA6_EndH		ds 1		; ($2D) Sample End Address/256 (MSB)

;==============================================================================;
; ADPCM-B variables (ports 4/5)
intPCM_ChanFlags	ds 1		; ($1C) *ADPCM-A and B flags control*

;------------------------------------------------------------------------------;
; * ADPCM-B
intPCMB_Status		ds 1		; ($10) Start, Repeat, Reset
intPCMB_LeftRight	ds 1		; ($11) Left and Right channel output
intPCMB_StartLo		ds 1		; ($12) Sample Start Address/256 (LSB)
intPCMB_StartHi		ds 1		; ($13) Sample Start Address/256 (MSB)
intPCMB_EndLo		ds 1		; ($14) Sample End Address/256 (LSB)
intPCMB_EndHi		ds 1		; ($15) Sample End Address/256 (MSB)
intPCMB_SampRateL	ds 1		; ($19) Delta-N Sampling Rate (L)
intPCMB_SampRateH	ds 1		; ($1A) Delta-N Sampling Rate (H)
intPCMB_Volume		ds 1		; ($1B) Channel volume

;==============================================================================;
; FM variables
;intFM_LSITest		ds 1		; ($21, 4/5) LSI test data
intFM_LFOFreq		ds 1		; ($22, 4/5) LFO Frequency Control
intFM_KeyOnOff		ds 1		; ($28, 4/5) Key On/Off, Slot

;------------------------------------------------------------------------------;
; * FM Channel 1
intFM1_Freq1		ds 1		; ($A1, 4/5) Frequency (LSB)
intFM1_Freq2		ds 1		; ($A5, 4/5) Block, Frequency (MSB)
intFM1_2Freq1		ds 1		; ($A9, 4/5) 2 CH*Frequency (LSB)
intFM1_2Freq2		ds 1		; ($AD, 4/5) 2 CH*Block, 2CH*Frequency (MSB)
intFM1_FbackAlgo	ds 1		; ($B1, 4/5) Self Feedback/Algorithm
intFM1_LefRgtAMPM	ds 1		; ($B5, 4/5) L/R select, AM and PM values

; Detune (DT1) and Multiple (MUL)
intFM1_DetuneMult1	ds 1		; ($31, 4/5) Op1 Detune/Multiple
intFM1_DetuneMult2	ds 1		; ($35, 4/5) Op2 Detune/Multiple
intFM1_DetuneMult3	ds 1		; ($39, 4/5) Op3 Detune/Multiple
intFM1_DetuneMult4	ds 1		; ($3D, 4/5) Op4 Detune/Multiple

; Total Level (TL)
intFM1_TotalLevel1	ds 1		; ($41, 4/5) Op1 Total Level
intFM1_TotalLevel2	ds 1		; ($45, 4/5) Op2 Total Level
intFM1_TotalLevel3	ds 1		; ($49, 4/5) Op3 Total Level
intFM1_TotalLevel4	ds 1		; ($4D, 4/5) Op4 Total Level

; Rate Scaling (RS), Attack Rate (AR)
intFM1_KeyScAtk1	ds 1		; ($51, 4/5) Op1 Key Scale/Attack
intFM1_KeyScAtk2	ds 1		; ($55, 4/5) Op2 Key Scale/Attack
intFM1_KeyScAtk3	ds 1		; ($59, 4/5) Op3 Key Scale/Attack
intFM1_KeyScAtk4	ds 1		; ($5D, 4/5) Op4 Key Scale/Attack

; Amplitude Modulation (AM), (first) Decay Rate (D1R)
intFM1_DecayAM1		ds 1		; ($61, 4/5) Op1 Decay/AM On
intFM1_DecayAM2		ds 1		; ($65, 4/5) Op2 Decay/AM On
intFM1_DecayAM3		ds 1		; ($69, 4/5) Op3 Decay/AM On
intFM1_DecayAM4		ds 1		; ($6D, 4/5) Op4 Decay/AM On

; Sustain ("secondary Decay Rate", D2R)
intFM1_Sustain1		ds 1		; ($71, 4/5) Op1 Sustain Rate
intFM1_Sustain2		ds 1		; ($75, 4/5) Op2 Sustain Rate
intFM1_Sustain3		ds 1		; ($79, 4/5) Op3 Sustain Rate
intFM1_Sustain4		ds 1		; ($7D, 4/5) Op4 Sustain Rate

; Sustain Level ("secondary Amplitude", D1L), Release Rate (RR)
intFM1_SusLvRel1	ds 1		; ($81, 4/5) Op1 Sustain Level/Release Rate
intFM1_SusLvRel2	ds 1		; ($85, 4/5) Op2 Sustain Level/Release Rate
intFM1_SusLvRel3	ds 1		; ($89, 4/5) Op3 Sustain Level/Release Rate
intFM1_SusLvRel4	ds 1		; ($8D, 4/5) Op4 Sustain Level/Release Rate

; SSG-type Envelope Control (SSG-EG)
intFM1_SSGEnvel1	ds 1		; ($91, 4/5) Op1 SSG-type Envelope control
intFM1_SSGEnvel2	ds 1		; ($95, 4/5) Op2 SSG-type Envelope control
intFM1_SSGEnvel3	ds 1		; ($99, 4/5) Op3 SSG-type Envelope control
intFM1_SSGEnvel4	ds 1		; ($9D, 4/5) Op4 SSG-type Envelope control

;------------------------------------------------------------------------------;
; * FM Channel 2
intFM2_Freq1		ds 1		; ($A2, 4/5) Frequency (LSB)
intFM2_Freq2		ds 1		; ($A6, 4/5) Block, Frequency (MSB)
intFM2_2Freq1		ds 1		; ($AA, 4/5) 2 CH*Frequency (LSB)
intFM2_2Freq2		ds 1		; ($AE, 4/5) 2 CH*Block, 2CH*Frequency (MSB)
intFM2_FbackAlgo	ds 1		; ($B2, 4/5) Self Feedback/Algorithm
intFM2_LRAMPM		ds 1		; ($B6, 4/5) L/R select, AM and PM values

intFM2_DetuneMult1	ds 1		; ($32, 4/5) Op1 Detune/Multiple
intFM2_DetuneMult2	ds 1		; ($36, 4/5) Op2 Detune/Multiple
intFM2_DetuneMult3	ds 1		; ($3A, 4/5) Op3 Detune/Multiple
intFM2_DetuneMult4	ds 1		; ($3E, 4/5) Op4 Detune/Multiple

intFM2_TotalLevel1	ds 1		; ($42, 4/5) Op1 Total Level
intFM2_TotalLevel2	ds 1		; ($46, 4/5) Op2 Total Level
intFM2_TotalLevel3	ds 1		; ($4A, 4/5) Op3 Total Level
intFM2_TotalLevel4	ds 1		; ($4E, 4/5) Op4 Total Level

intFM2_KeyScAtk1	ds 1		; ($52, 4/5) Op1 Key Scale/Attack
intFM2_KeyScAtk2	ds 1		; ($56, 4/5) Op2 Key Scale/Attack
intFM2_KeyScAtk3	ds 1		; ($5A, 4/5) Op3 Key Scale/Attack
intFM2_KeyScAtk4	ds 1		; ($5E, 4/5) Op4 Key Scale/Attack

intFM2_DecayAM1		ds 1		; ($62, 4/5) Op1 Decay/AM On
intFM2_DecayAM2		ds 1		; ($66, 4/5) Op2 Decay/AM On
intFM2_DecayAM3		ds 1		; ($6A, 4/5) Op3 Decay/AM On
intFM2_DecayAM4		ds 1		; ($6E, 4/5) Op4 Decay/AM On

intFM2_Sustain1		ds 1		; ($72, 4/5) Op1 Sustain Rate
intFM2_Sustain2		ds 1		; ($76, 4/5) Op2 Sustain Rate
intFM2_Sustain3		ds 1		; ($7A, 4/5) Op3 Sustain Rate
intFM2_Sustain4		ds 1		; ($7E, 4/5) Op4 Sustain Rate

intFM2_SusLvRel1	ds 1		; ($82, 4/5) Op1 Sustain Level/Release Rate
intFM2_SusLvRel2	ds 1		; ($86, 4/5) Op2 Sustain Level/Release Rate
intFM2_SusLvRel3	ds 1		; ($8A, 4/5) Op3 Sustain Level/Release Rate
intFM2_SusLvRel4	ds 1		; ($8E, 4/5) Op4 Sustain Level/Release Rate

intFM2_SSGEnvel1	ds 1		; ($92, 4/5) Op1 SSG-type Envelope control
intFM2_SSGEnvel2	ds 1		; ($96, 4/5) Op2 SSG-type Envelope control
intFM2_SSGEnvel3	ds 1		; ($9A, 4/5) Op3 SSG-type Envelope control
intFM2_SSGEnvel4	ds 1		; ($9E, 4/5) Op4 SSG-type Envelope control

;------------------------------------------------------------------------------;
; * FM Channel 3
intFM3_Freq1		ds 1		; ($A1, 6/7) Frequency (LSB)
intFM3_Freq2		ds 1		; ($A5, 6/7) Block, Frequency (MSB)
intFM3_2Freq1		ds 1		; ($A9, 6/7) 2 CH*Frequency (LSB)
intFM3_2Freq2		ds 1		; ($AD, 6/7) 2 CH*Block, 2CH*Frequency (MSB)
intFM3_FbackAlgo	ds 1		; ($B1, 6/7) Self Feedback/Algorithm
intFM3_LRAMPM		ds 1		; ($B5, 6/7) L/R select, AM and PM values

intFM3_DetuneMult1	ds 1		; ($31, 6/7) Op1 Detune/Multiple
intFM3_DetuneMult2	ds 1		; ($35, 6/7) Op2 Detune/Multiple
intFM3_DetuneMult3	ds 1		; ($39, 6/7) Op3 Detune/Multiple
intFM3_DetuneMult4	ds 1		; ($3D, 6/7) Op4 Detune/Multiple

intFM3_TotalLevel1	ds 1		; ($41, 6/7) Op1 Total Level
intFM3_TotalLevel2	ds 1		; ($45, 6/7) Op2 Total Level
intFM3_TotalLevel3	ds 1		; ($49, 6/7) Op3 Total Level
intFM3_TotalLevel4	ds 1		; ($4D, 6/7) Op4 Total Level

intFM3_KeyScAtk1	ds 1		; ($51, 6/7) Op1 Key Scale/Attack
intFM3_KeyScAtk2	ds 1		; ($55, 6/7) Op2 Key Scale/Attack
intFM3_KeyScAtk3	ds 1		; ($59, 6/7) Op3 Key Scale/Attack
intFM3_KeyScAtk4	ds 1		; ($5D, 6/7) Op4 Key Scale/Attack

intFM3_DecayAM1		ds 1		; ($61, 6/7) Op1 Decay/AM On
intFM3_DecayAM2		ds 1		; ($65, 6/7) Op2 Decay/AM On
intFM3_DecayAM3		ds 1		; ($69, 6/7) Op3 Decay/AM On
intFM3_DecayAM4		ds 1		; ($6D, 6/7) Op4 Decay/AM On

intFM3_Sustain1		ds 1		; ($71, 6/7) Op1 Sustain Rate
intFM3_Sustain2		ds 1		; ($75, 6/7) Op2 Sustain Rate
intFM3_Sustain3		ds 1		; ($79, 6/7) Op3 Sustain Rate
intFM3_Sustain4		ds 1		; ($7D, 6/7) Op4 Sustain Rate

intFM3_SusLvRel1	ds 1		; ($81, 6/7) Op1 Sustain Level/Release Rate
intFM3_SusLvRel2	ds 1		; ($85, 6/7) Op2 Sustain Level/Release Rate
intFM3_SusLvRel3	ds 1		; ($89, 6/7) Op3 Sustain Level/Release Rate
intFM3_SusLvRel4	ds 1		; ($8D, 6/7) Op4 Sustain Level/Release Rate

intFM3_SSGEnvel1	ds 1		; ($91, 6/7) Op1 SSG-type Envelope control
intFM3_SSGEnvel2	ds 1		; ($95, 6/7) Op2 SSG-type Envelope control
intFM3_SSGEnvel3	ds 1		; ($99, 6/7) Op3 SSG-type Envelope control
intFM3_SSGEnvel4	ds 1		; ($9D, 6/7) Op4 SSG-type Envelope control

;------------------------------------------------------------------------------;
; * FM Channel 4
intFM4_Freq1		ds 1		; ($A2, 6/7) Frequency 1 (LSB)
intFM4_Freq2		ds 1		; ($A6, 6/7) Block, Frequency 2 (MSB)
intFM4_2Freq1		ds 1		; ($AA, 6/7) 2 CH*Frequency 1 (LSB)
intFM4_2Freq2		ds 1		; ($AE, 6/7) 2 CH*Block, 2CH*Frequency 2 (MSB)
intFM4_FbackAlgo	ds 1		; ($B2, 6/7) Self Feedback/Algorithm
intFM4_LRAMPM		ds 1		; ($B6, 6/7) L/R select, AM and PM values

intFM4_DetuneMult1	ds 1		; ($32, 6/7) Op1 Detune/Multiple
intFM4_DetuneMult2	ds 1		; ($36, 6/7) Op2 Detune/Multiple
intFM4_DetuneMult3	ds 1		; ($3A, 6/7) Op3 Detune/Multiple
intFM4_DetuneMult4	ds 1		; ($3E, 6/7) Op4 Detune/Multiple

intFM4_TotalLevel1	ds 1		; ($42, 6/7) Op1 Total Level
intFM4_TotalLevel2	ds 1		; ($46, 6/7) Op2 Total Level
intFM4_TotalLevel3	ds 1		; ($4A, 6/7) Op3 Total Level
intFM4_TotalLevel4	ds 1		; ($4E, 6/7) Op4 Total Level

intFM4_KeyScAtk1	ds 1		; ($52, 6/7) Op1 Key Scale/Attack
intFM4_KeyScAtk2	ds 1		; ($56, 6/7) Op2 Key Scale/Attack
intFM4_KeyScAtk3	ds 1		; ($5A, 6/7) Op3 Key Scale/Attack
intFM4_KeyScAtk4	ds 1		; ($5E, 6/7) Op4 Key Scale/Attack

intFM4_DecayAM1		ds 1		; ($62, 6/7) Op1 Decay/AM On
intFM4_DecayAM2		ds 1		; ($66, 6/7) Op2 Decay/AM On
intFM4_DecayAM3		ds 1		; ($6A, 6/7) Op3 Decay/AM On
intFM4_DecayAM4		ds 1		; ($6E, 6/7) Op4 Decay/AM On

intFM4_Sustain1		ds 1		; ($72, 6/7) Op1 Sustain Rate
intFM4_Sustain2		ds 1		; ($76, 6/7) Op2 Sustain Rate
intFM4_Sustain3		ds 1		; ($7A, 6/7) Op3 Sustain Rate
intFM4_Sustain4		ds 1		; ($7E, 6/7) Op4 Sustain Rate

intFM4_SusLvRel1	ds 1		; ($82, 6/7) Op1 Sustain Level/Release Rate
intFM4_SusLvRel2	ds 1		; ($86, 6/7) Op2 Sustain Level/Release Rate
intFM4_SusLvRel3	ds 1		; ($8A, 6/7) Op3 Sustain Level/Release Rate
intFM4_SusLvRel4	ds 1		; ($8E, 6/7) Op4 Sustain Level/Release Rate

intFM4_SSGEnvel1	ds 1		; ($92, 6/7) Op1 SSG-type Envelope control
intFM4_SSGEnvel2	ds 1		; ($96, 6/7) Op2 SSG-type Envelope control
intFM4_SSGEnvel3	ds 1		; ($9A, 6/7) Op3 SSG-type Envelope control
intFM4_SSGEnvel4	ds 1		; ($9E, 6/7) Op4 SSG-type Envelope control