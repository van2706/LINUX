.PHONY: build clean log-% all
PATH := .
CFALG:= gcc
INCLUDE_PATH := $(PATH)/include
SOURCE_PATH := $(PATH)/source
OUTPUT_PATH := $(PATH)/output
INCLUDE_FILE:= $(foreach INCLUDE_PATH, $(INCLUDE_PATH), $(wildcard $(INCLUDE_PATH)/*.h))
SOURCE_FILE := $(foreach SOURCE_PATH, $(SOURCE_PATH), $(wildcard $(SOURCE_PATH)/*.c))
OBJ_FILE := $(notdir $(SOURCE_FILE))
OBJ_FILE := $(subst .c,.o,$(OBJ_FILE))
OBJ_PATH := $(foreach OBJ_FILE, $(OBJ_FILE), $(OUTPUT_PATH)/$(OBJ_FILE))
vpath %.c $(SOURCE_PATH)
vpath %.h $(INCLUDE_PATH)
build:$(OBJ_FILE)
	gcc -o $(OUTPUT_PATH)/app $(OBJ_PATH)
%.o:%.c $(INCLUDE_FILE)
	gcc -c $< -o $(OUTPUT_PATH)/$@ -I$(INCLUDE_PATH)
all:
	gcc -c main.c -o output/main.o -I./include
log-%:
	@echo "$($(subst log-,,$@))"