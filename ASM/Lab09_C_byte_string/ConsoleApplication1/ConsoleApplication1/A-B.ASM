;��������� ������������ � ������ A_B ����
;   Procedure (var A: LONGWORD; const B:LONGWORD; L:LONGWORD)
;����������� ��������� ������� ����� A:=A \ B ����� L. 
.386
.model FLAT,C
PUBLIC A_B

.CODE
A_B PROC
	
  	; ����������
	PUSH EBP		; ���������� �������� ���������� ������� 
	MOV EBP,ESP		; ���������� ������� ������� � ����� 
	PUSH EBX		; ��������� �������

	MOV ESI,[EBP+16] ; ������ A	
	MOV EBX,[EBP+12] ; ������ B

	MOV EAX,[ESI] ; ������ A
	MOV EDX,[EBX] ; ������ B

	NOT EDX  ; ������ B
	AND EAX, EDX; toA

	MOV [ESI], EAX

	ADD EBX,4	
	ADD ESI,4

	MOV EAX,[ESI] ; ������ A
	MOV EDX,[EBX] ; ������ B

	NOT EDX  ; ������ B
	AND EAX, EDX; toA

	MOV [ESI], EAX



	NOT EBX
	AND ESI, EBX

	MOV [ESI], EAX

	POP EBX
	MOV ESP,EBP
	POP EBP
  RET 12
  A_B ENDP
END
