//
// Created by AW on 2020/11/25.
//

#ifndef UNTITLED2_INDEX_H
#define UNTITLED2_INDEX_H

#endif //UNTITLED2_INDEX_H

int Index(char *Frname){
    HString S,Q;
    FILE *fp;
    fp = fopen(Frname,"rb");
    fseek(fp,0,SEEK_END);
    int file_size = ftell(fp);
    int count=0;             //数出换行符数目
    char ch;
    fseek(fp,0,SEEK_SET);
    printf("文件中的内容如下:\n");
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n') count++;
        putchar(ch);
    }
    file_size-=count;

    int i=0;                 //将文件中的字符写入S.ch
    fseek(fp,0,SEEK_SET);
    S.ch =(char *)malloc(file_size * sizeof(char));
    while((ch=fgetc(fp))!=EOF)
        if(ch!='\n') {S.ch[i]=ch;i++;}
    S.ch[i]='\0';
    S.length=file_size+1;

    printf("\n请输入模式串：\n");
    Q.ch =(char *)malloc(XSIZE* sizeof(char));
    Q.length=0;
    ch=getchar();
    if(ch!='\n')
        Q.ch[Q.length++]=ch;
    while(ch!='\n')
    {
        ch=getchar();
        Q.ch[Q.length++]=ch;
    }
    Q.ch[Q.length]='\0';
    Q.length--;
    BM(Q,Q.length,S,S.length);


    /////////////////////////////////
    /*
    long file_len;
    long writen_len = 0;		// 控制文件写入长度
    FILE *infile;
    int char_kinds;		// 存储字符种类
    int node_num;
    HufTree huf_tree;
    char code_temp;		// 暂存8bits编码
    int root;		// 保存根节点索引，供匹配编码使用

    infile = fopen(Frname, "r");		// 以二进制方式打开压缩文件
    // 判断输入文件是否存在
    if (infile == NULL)
        return -1;

    // 读取压缩文件前端的字符及对应编码，用于重建哈夫曼树
    fread((char *)&char_kinds, sizeof(unsigned int), 1, infile);     // 读取字符种类数
    if (char_kinds == 1)
    {
        fread((char *)&code_temp, sizeof(unsigned char), 1, infile);     // 读取唯一的字符
        fread((char *)&file_len, sizeof(unsigned long), 1, infile);     // 读取文件长度
        while (file_len--)
            fclose(infile);
    }
    else
    {
        node_num = 2 * char_kinds - 1;		// 根据字符种类数，计算建立哈夫曼树所需结点数
        huf_tree = (HufNode *)malloc(node_num*sizeof(HufNode));		// 动态分配哈夫曼树结点空间
        // 读取字符及对应权重，存入哈夫曼树节点
        for(i = 0; i < char_kinds; ++i)
        {
            fread((char *)&huf_tree[i].uch, sizeof(unsigned char), 1, infile);		// 读入字符
            fread((char *)&huf_tree[i].weight, sizeof(unsigned long), 1, infile);	// 读入字符对应权重
            huf_tree[i].parent = 0;
        }
        // 初始化后node_num-char_kins个结点的parent

        for(; i < node_num; ++i)
            huf_tree[i].parent = 0;

        CreateTree(huf_tree, char_kinds, node_num);		// 重建哈夫曼树（与压缩时的一致）
        HufCode(huf_tree, char_kinds);		// 生成哈夫曼编码
        codetype code[char_kinds+1];
        Gethufcode(code, huf_tree, char_kinds);
        hufcode(code, char_kinds);//放进bit二维数组便于索引字符串
        */
}
