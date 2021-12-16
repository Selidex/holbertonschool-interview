#!/usr/bin/python3
""" This file will be API"""
from collections import OrderedDict
import requests
import sys


def count_words(subreddit, word_list=[], hot_list=[]):
    """Recursion"""
    if subreddit is None:
        return None
    url = "https://www.reddit.com/r/" + str(subreddit) + "/hot/.json"
    headers = {'User-Agent': 'Sel'}
    if len(hot_list) < 1:
        r = requests.get(url, headers=headers, allow_redirects=False)
        if r.status_code != 200:
                    return None
        after = r.json().get('data').get('after')
        hot_list.append(after)
    else:
        url = str(url) + "?after=" + str(hot_list[0]) + "&limit=100"
        r = requests.get(url, headers=headers, allow_redirects=False)
    if r.status_code != 200:
        return None
    after = r.json().get('data').get('after')
    hot_list[0] = after
    rj = r.json().get('data').get('children')
    for post in rj:
        child_dict = post['data']
        hot_list.append(child_dict.get('title'))
    if after is None:
        hot_list.pop(0)
        zhuli(word_list, hot_list)
        return
    else:
        return count_words(subreddit, word_list, hot_list)


def zhuli(word_list=[], hot_list=[]):
    """Zhu Li, Do The Thing"""
    word_dict = {}
    for y in word_list:
            temp = y.lower()
            if temp not in word_dict:
                word_dict[temp] = 0
            for x in hot_list:
                word_dict[temp] += x.lower().split().count(temp)
    word_dict = OrderedDict(sorted(word_dict.items()))
    sort_word = sorted(word_dict.items(), key=lambda x: x[1], reverse=True)
    for x in sort_word:
        if x[1] == 0:
            return
        print("{}: {}".format(x[0], x[1]))
