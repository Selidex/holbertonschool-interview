#!/usr/bin/python3
""" This file will be API"""
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

        return
    else:
        return count_words(subreddit, word_list, hot_list)
